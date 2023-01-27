#ifndef SOMAPARAMETERS
#define SOMAPARAMETERS

#include <string>

using std::string;
using std::to_string;

struct SOMAParameters
	: EAParameters
{
	double PathLength;
	double Step;
	double PRT;
	double MinDiv;

	SOMAParameters(int dim, int pop, int mig, double pathLength, double step, double prt, double minDiv)
		: EAParameters(dim, pop, mig)
	{
		PathLength = pathLength;
		Step = step;
		PRT = prt;
		MinDiv = minDiv;
	}

	string ToString()
	{
		string result = "Algorithm: SOMA\nDimension: ";

		result += to_string(Dimension);
		result += "\nPopulation: ";
		result += to_string(Population);
		result += "\nMigrations: ";
		result += to_string(Iterations);
		result += "\nPathLength: ";
		result += to_string(PathLength);
		result += "\nStep: ";
		result += to_string(Step);
		result += "\nPRT: ";
		result += to_string(PRT);
		result += "\nMinDiv: ";
		result += to_string(MinDiv);

		return result;
	}
};

#endif
