#ifndef EVOLUTIONARYALGORITHM
#define EVOLUTIONARYALGORITHM

#include "../inc/rand.h"

class EvolutionaryAlgorithm
{
private:
	double APThreshold;

protected:
	EAParameters* parameters;
	Population* pop = NULL;
	Specimen* spec;
	double (*costF)(int, Individual*);
	bool showProgress = true;

	Individual* GetPopBest()
	{
		return pop->GetLeader();
	}

	void Information(Individual* leader, int iteration)
	{
		if (showProgress)
		{
			printf("%d / %d: %f\n", iteration, parameters->Iterations, leader->GetCost());
		}
	}

public:
	EvolutionaryAlgorithm(EAParameters* params, Specimen& specimen, double (*costFunction)(int, Individual*))
	{
		parameters = params;
		spec = &specimen;
		costF = costFunction;
	}

	virtual ~EvolutionaryAlgorithm()
	{
		delete pop;
	}

	void ShowProgress(bool show)
	{
		showProgress = show;
	}

	virtual bool Iteration(Population* population) = 0;

	virtual Individual* GetBestSolution()
	{
		pop = new Population(parameters->Dimension, parameters->Population, (*spec), costF);
		int i;

		for (i = 0; i < parameters->Iterations; i++)
		{
			Individual* leader = GetPopBest();
			Information(leader, i);

			if (!Iteration(pop))
			{
				i++;
				break;
			}
		}

		Individual* popBest = GetPopBest();
		Information(popBest, i);

		return popBest;
	}
};

#endif
