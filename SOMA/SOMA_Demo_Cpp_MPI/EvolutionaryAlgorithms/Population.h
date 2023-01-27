#ifndef POPULATION
#define POPULATION

#include "Individual.h"

class Population
{
private:
	int size;
	double (*costF)(int, Individual*);
	Individual** population;

public:
	Population(int dim, int popSize, Specimen &spec, double (*costFunction)(int, Individual*))
	{
		size = popSize;
		population = new Individual*[popSize];
		costF = costFunction;

		for (int i = 0; i < size; i++)
		{
			population[i] = new Individual(dim, spec, costFunction);
		}
	}

	Population(json& j, double (*costFunction)(int, Individual*))
	{
		costF = costFunction;
		size = j["size"].get<int>();
		vector<json> popMembers = j["population"].get<vector<json>>();
		population = new Individual*[size];

		for (int i = 0; i < size; i++)
		{
			population[i] = new Individual(popMembers[i], costF);
		}
	}

	virtual ~Population()
	{
		for (int i = 0; i < size; i++)
		{
			delete population[i];
		}

		delete[] population;
	}
	
	Individual* GetIndividual(int index)
	{
    	return population[index];
    }
	
	void SetIndividual(int index, Individual* ind)
	{
    	population[index] = ind;
    }

	Individual* GetLeader()
	{
		Individual* result = population[0];

		for (int i = 1; i < size; i++)
		{
			if (population[i]->LowerThan(result))
			{
				result = population[i];
			}
		}

		return result;
	}
	
	void Serialize(json& j, bool withExpression)
	{
		j["size"] = size;
		j["population"] = json::array();

		for (int i = 0; i < size; i++)
		{
			json ind;
			population[i]->Serialize(ind, withExpression);
			j["population"].push_back(ind);
		}
	}
};

#endif
