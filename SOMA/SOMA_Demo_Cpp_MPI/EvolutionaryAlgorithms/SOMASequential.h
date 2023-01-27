#ifndef SOMASEQUENTIAL
#define SOMASEQUENTIAL

#include "EvolutionaryAlgorithm.h"

class SOMASequential
	: public EvolutionaryAlgorithm
{
private:
	SOMAParameters* pars;
	static void NewSOMAIndividual(int, double*, va_list);

public:
	SOMASequential(SOMAParameters* params, Specimen& specimen, double (*costFunction)(int, Individual*))
		: EvolutionaryAlgorithm(params, specimen, costFunction)
	{
		pars = params;
	}

	~SOMASequential()
	{
		
	}

	bool Iteration(Population* pop)
	{
		Individual* leader = pop->GetLeader();

		for (int i = 0; i < pars->Population; i++)
		{
			Individual* actual = pop->GetIndividual(i);
			// TODO implement if (leader == ind) continue;
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
				delete actual;
				pop->SetIndividual(i, stepLeader);
			}
			else
			{
				delete stepLeader;
			}
		}

		return true;
	}
};

void SOMASequential::NewSOMAIndividual(int dim, double* params, va_list vl)
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
