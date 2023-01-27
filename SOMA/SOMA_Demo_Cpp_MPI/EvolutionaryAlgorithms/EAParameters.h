#ifndef EAPARAMETERS
#define EAPARAMETERS

#include <string>

using std::string;
using std::to_string;

struct EAParameters
{
	int Dimension;
	int Population;
	int Iterations;

	EAParameters(int dim, int pop, int iter)
	{
		Dimension = dim;
		Population = pop;
		Iterations = iter;
	}

	virtual string ToString() = 0;
};

#endif
