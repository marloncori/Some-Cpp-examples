#ifndef RAND
#define RAND

#include <string.h>
#include <time.h>
#include <math.h>
#include <limits>
#include "mt.cpp"

// The smallest double
const double epsilon = std::numeric_limits<double>::min();

// 2 PI
const double two_pi = 2.0 * M_PI;

// Function that returns random number in interval <0; 1)
double (*myRand)();

// Indicator whether to use only x (X) or y (Y) or both (B) coordinates from chaos generator
char coord;

// Indicator whether to use x coordinate
bool coordX;

// Represents MersenneTwister generator
MersenneTwister mersenne;

// Gets a random number within specified interval
double getRandom(double min, double max)
{
	double result = myRand();
	
	// Limits defined in chaos generators are rounded and there can be results outside this range
	// At first, try to change sign or remove 1, in most cases sufficient and gives different than constant results
	if (result < 0) result = -result;
	if (result >= 1) result -= 1;
	// After adjust if now result is out of range, adjust it by constant
	if (result < 0) result = 0;
	if (result >= 1) result = 1 - std::numeric_limits<double>::min();
	// Switch used coordinate if both are desired
	if (coord == 'B') coordX = !coordX;
	
	return result * (max - min) + min;
}

// Gets a uniformly distributed random number
double getUniform()
{
    return ((double)rand() / (double)RAND_MAX);
}

// Gets a uniformly distributed random number from Mersenne Twister
double getMersenne()
{
	return mersenne.random();
}

// Gets a random number from Logistic map
double getLogistic()
{
	static double x = 0.02;
	return x = 4 * x * (1 - x);
}

// Gets a normally distributed random number in specified interval (Box–Muller transform)
double getRandomGaussian(double mu, double sigma)
{
	static double z0;
	static double z1;
	static bool generate;

	if (!(generate = !generate))
		return z1 * sigma + mu;

	double u1, u2;

	do
	{
		u1 = myRand();
		u2 = myRand();
	} while (u1 <= epsilon);

	z0 = sqrt(-2.0 * log(u1)) * cos(two_pi * u2);
	z1 = sqrt(-2.0 * log(u1)) * sin(two_pi * u2);
	
	return z0 * sigma + mu;
}

// Inits a random number generator
void initRandom(int seed, int argc, char** argv)
{
	char* randType = argv[1];
	coord = argv[2][0];
	coordX = coord == 'X';

	if (strcmp(randType, "LOGISTIC") == 0)
	{
		myRand = &getLogistic;
	}
	else if (strcmp(randType, "MERSENNE") == 0)
	{
		mersenne.init_genrand(time(NULL) + seed);
		myRand = &getMersenne;
		return;
	}
	else
	{
		srand(time(NULL) + seed);
		myRand = &getUniform;
		return;
	}
	
	for (int i = 0; i < seed + time(NULL) % 100; i++)
	{
		myRand();
	}
}

#endif
