#ifndef SOMAPARALLEL
#define SOMAPARALLEL

#define WORKTAG	1
#define DIETAG	2

#include "ParallelEvolutionaryAlgorithm.h"

class SOMAParallel
	: public ParallelEvolutionaryAlgorithm
{
private:
	SOMAParameters* pars;
	static void NewSOMAIndividual(int, double*, va_list);

	void EvaluatePopulation(bool initial)
	{
		MPI_Status status;
		int i = 0;
		int msgSize;
		Individual* leader;

		if (rank == 0)
		{
			if (!initial)
				leader = pop->GetLeader();

			for (int j = 1; j < size && i < pars->Population; j++, i++)
			{
				MPI_Send(&i, 1, MPI_INT, j, WORKTAG, MPI_COMM_WORLD);
				positions[j] = i;
			}

			int pos;

			for (; i < pars->Population; i++)
			{
				if (!initial && pop->GetIndividual(i) == leader)
					continue;

				MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
				MPI_Get_count(&status, MPI_CHAR, &msgSize);
				pos = positions[status.MPI_SOURCE];
				char* incoming = new char[msgSize];
				MPI_Recv(incoming, msgSize, MPI_CHAR, status.MPI_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				json recInd = json::parse(incoming);
				Individual* newInd = new Individual(recInd, costF);

				if (initial || newInd->LowerThan(pop->GetIndividual(pos)))
				{
					delete pop->GetIndividual(pos);
					pop->SetIndividual(pos, newInd);
				}
				else
				{
					delete newInd;
				}

				delete[] incoming;
				positions[status.MPI_SOURCE] = i;
				MPI_Send(&i, 1, MPI_INT, status.MPI_SOURCE, WORKTAG, MPI_COMM_WORLD);
			}

			i = 0;

			for (int j = 1; j < size && i < pars->Population; j++, i++)
			{	
				MPI_Probe(MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, &status);
				MPI_Get_count(&status, MPI_CHAR, &msgSize);
				pos = positions[status.MPI_SOURCE];
				char* incoming = new char[msgSize];
				MPI_Recv(incoming, msgSize, MPI_CHAR, status.MPI_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
				json recInd = json::parse(incoming);
				Individual* newInd = new Individual(recInd, costF);

				if (initial || newInd->LowerThan(pop->GetIndividual(pos)))
				{
					delete pop->GetIndividual(pos);
					pop->SetIndividual(pos, newInd);
				}
				else
				{
					delete newInd;
				}

				delete[] incoming;
			}

			for (int j = 1; j < size; j++)
			{
				MPI_Send(0, 0, MPI_INT, j, DIETAG, MPI_COMM_WORLD);
			}
		}
		else if (initial)
		{
			while (true)
			{
				MPI_Recv(&i, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

				if (status.MPI_TAG == DIETAG)
					return;
				
				Individual* actual = pop->GetIndividual(i);
				actual->GetCost();
				json sndInd;
				actual->Serialize(sndInd, true);
				string sndStr = sndInd.dump();
				char* serInd = (char*)sndStr.c_str();
				MPI_Send(serInd, sndStr.length() + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
			}
		}
		else
		{
			leader = pop->GetLeader();

			while (true)
			{
				MPI_Recv(&i, 1, MPI_INT, 0, MPI_ANY_TAG, MPI_COMM_WORLD, &status);

				if (status.MPI_TAG == DIETAG)
					return;

				Individual* actual = pop->GetIndividual(i);
				Individual* stepLeader = NULL;

				for (double t = 0; t < pars->PathLength; t += pars->Step)
				{
					Individual* newInd = new Individual(pars->Dimension, (*spec), costF, NewSOMAIndividual, t, pars->PRT, leader, actual);

					if (!spec->IsInBounds(newInd->params))
					{
						spec->GetParameters(newInd->params);
					}

					if (stepLeader == NULL || newInd->LowerThan(stepLeader))
					{
						delete stepLeader;
						stepLeader = newInd;
					}
					else
					{
						delete newInd;
					}
				}

				if (stepLeader->LowerThan(actual))
				{
					//From some reason this does not work properly...
					//delete pop->GetIndividual(i);
					pop->SetIndividual(i, stepLeader);
				}
				else
				{
					delete stepLeader;
				}
				
				json sndInd;
				pop->GetIndividual(i)->Serialize(sndInd, true);
				string sndStr = sndInd.dump();
				char* serInd = (char*)sndStr.c_str();
				MPI_Send(serInd, sndStr.length() + 1, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
			}
		}
	}

public:
	SOMAParallel(SOMAParameters* params, Specimen& specimen, double (*costFunction)(int, Individual*), int rank, int size)
		: ParallelEvolutionaryAlgorithm(params, specimen, costFunction, rank, size)
	{
		pars = params;
	}

	~SOMAParallel()
	{

	}
};

void SOMAParallel::NewSOMAIndividual(int dim, double* params, va_list vl)
{
	double t = va_arg(vl, double);
	double PRT = va_arg(vl, double);
	Individual* leader = va_arg(vl, Individual*);
	Individual* ind = va_arg(vl, Individual*);
	bool prtNonZero = false;

	for (int i = 0; i < dim; i++)
	{
		double prt = getRandom(0, 1) < PRT ? 1 : 0;

		if (prt == 1)
		{
			prtNonZero = true;
		}
		else if (!prtNonZero && i == dim - 1)
		{
			prt = 1;
		}

		params[i] = (*ind)[i] + ((*leader)[i] - (*ind)[i]) * t * prt;
	}
}

#endif
