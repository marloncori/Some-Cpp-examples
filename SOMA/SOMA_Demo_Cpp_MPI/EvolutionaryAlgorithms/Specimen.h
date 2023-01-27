#ifndef SPECIMEN
#define SPECIMEN

#include "../inc/rand.h"

class Specimen
{
private:
	int dim;
	double low;
	double high;

public:
	Specimen(int dimension, double lowerBound, double upperBound)
	{
		dim = dimension;
		low = lowerBound;
		high = upperBound;
	}

	void GetParameters(double* params)
	{
		for (int i = 0; i < dim; i++)
		{
			params[i] = getRandom(low, high);
		}
	}

	bool IsInBounds(double* params)
	{
		for (int i = 0; i < dim; i++)
		{
			if (params[i] > high || params[i] < low)
				return false;
		}

		return true;
	}

	void ReinforcedEnable()
	{
		static bool reinforced = false;

		if (!reinforced)
		{
			reinforced = true;
			high++;
		}
	}
};

#endif