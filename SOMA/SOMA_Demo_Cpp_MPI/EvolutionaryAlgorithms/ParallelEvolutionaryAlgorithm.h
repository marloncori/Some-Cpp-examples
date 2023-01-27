#ifndef PARALLELEVOLUTIONARYALGORITHM
#define PARALLELEVOLUTIONARYALGORITHM

#include "../inc/json.hpp"
#include "EvolutionaryAlgorithm.h"

class ParallelEvolutionaryAlgorithm
	: public EvolutionaryAlgorithm
{
protected:
	int rank;
	int size;
	int* positions;
	virtual void EvaluatePopulation(bool) = 0;

	virtual void DistributePopulation()
	{
		if (rank == 0)
		{
			json sPop;
			pop->Serialize(sPop, true);
			string strPop = sPop.dump();
			char* serPop = (char*)strPop.c_str();
			int sPopLen = strPop.length() + 1;
			MPI_Bcast(&sPopLen, 1, MPI_INT, 0, MPI_COMM_WORLD);
			MPI_Bcast(serPop, sPopLen, MPI_CHAR, 0, MPI_COMM_WORLD);
		}
		else
		{
			int sPopLen;
			MPI_Bcast(&sPopLen, 1, MPI_INT, 0, MPI_COMM_WORLD);
			char* inPop = new char[sPopLen];
			MPI_Bcast(inPop, sPopLen, MPI_CHAR, 0, MPI_COMM_WORLD);
			json sPop = json::parse(inPop);
			delete pop;
			pop = new Population(sPop, costF);
			delete[] inPop;
		}
	}

public:
	ParallelEvolutionaryAlgorithm(EAParameters* params, Specimen& specimen, double (*costFunction)(int, Individual*), int rankNo, int wSize)
		: EvolutionaryAlgorithm(params, specimen, costFunction)
	{
		rank = rankNo;
		size = wSize;
		positions = new int[size];
	}

	virtual ~ParallelEvolutionaryAlgorithm()
	{
		delete[] positions;
	}

	virtual bool Iteration(Population* pop)
	{
		DistributePopulation();
		EvaluatePopulation(false);

		return true;
	}
	
	virtual Individual* GetBestSolution()
	{
		if (rank == 0)
		{
			pop = new Population(parameters->Dimension, parameters->Population, (*spec), costF);
		}

		DistributePopulation();
		EvaluatePopulation(true);

		int i;

		for (i = 0; i < parameters->Iterations; i++)
		{
			if (rank == 0)
			{
				Individual* leader = GetPopBest();
				Information(leader, i);
			}

			if (!Iteration(pop))
			{
				i++;
				break;
			}
		}

		if (rank == 0)
		{
			Individual* result = GetPopBest();
			Information(result, i);
			return result;
		}
		else
		{
			return NULL;
		}
	}
};

#endif
