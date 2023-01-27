#ifndef INDIVIDUAL
#define INDIVIDUAL

#include <stdarg.h>
#include <vector>
#include "Specimen.h"
#include "../inc/json.hpp"

using json = nlohmann::json;
using std::vector;

class Individual
{
private:
	double (*costF)(int, Individual*);

public:
	static int CostEvaluations;
	double* params;
	bool evaluated = false;
	double cost;
	int dimension;

	Individual(int dim, Specimen& spec, double (*costFunction)(int, Individual*))
	{
		dimension = dim;
		params = new double[dim];
		spec.GetParameters(params);
		costF = costFunction;
	}

	Individual(int dim, Specimen& spec, double (*costFunction)(int, Individual*), void (*sumFunc)(int, double*, va_list), ...)
	{
		dimension = dim;
		params = new double[dim];
		costF = costFunction;

		va_list args;
		va_start(args, sumFunc);
		sumFunc(dim, params, args);
		va_end(args);
	}

	Individual(json& j, double (*costFunction)(int, Individual*))
	{
		costF = costFunction;
		evaluated = j["evaluated"].get<bool>();
		cost = j["cost"].get<double>();
		dimension = j["dimension"].get<int>();
		vector<double> indParams = j["params"].get<vector<double>>();
		params = new double[dimension];

		for (int i = 0; i < dimension; i++)
		{
			params[i] = indParams[i];
		}
	}

	virtual ~Individual()
	{
		delete[] params;
	}
	
	double& operator[] (int index)
	{
    	return params[index];
    }

	double GetCost()
	{
		if (!evaluated)
		{
			evaluated = true;
			cost = costF(dimension, this);
			CostEvaluations++;
		}

		return cost;
	}

	bool LowerThan(Individual* other)
	{
		double tCost = GetCost();
		double oCost = other->GetCost();

		return tCost < oCost;
	}
	
	void Serialize(json& j, bool withExpression)
	{
		j["evaluated"] = evaluated;
		j["cost"] = cost;
		j["dimension"] = dimension;
		j["params"] = json::array();

		for (int i = 0; i < dimension; i++)
		{
			j["params"].push_back(params[i]);
		}
	}
};

int Individual::CostEvaluations = 0;

#endif
