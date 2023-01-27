#include <stdio.h>
#include <mpi.h>
#include "EvolutionaryAlgorithms/EAParameters.h"
#include "EvolutionaryAlgorithms/SOMAParameters.h"
#include "inc/rand.h"
#include "EvolutionaryAlgorithms/Specimen.h"
#include "EvolutionaryAlgorithms/Individual.h"
#include "EvolutionaryAlgorithms/Population.h"
#include "EvolutionaryAlgorithms/EvolutionaryAlgorithm.h"
#include "EvolutionaryAlgorithms/ParallelEvolutionaryAlgorithm.h"
#include "EvolutionaryAlgorithms/SOMASequential.h"
#include "EvolutionaryAlgorithms/SOMAParallel.h"

double DeJong(int dim, Individual* ind)
{
	double result = 0;

	for (int i = 0; i < dim; i++)
	{
		result += (*ind)[i] * (*ind)[i];
	}

	return result;
}

double Schwefel(int dim, Individual* ind)
{
	double result = 0;

	for (int i = 0; i < dim; i++)
	{
		result -= (*ind)[i] * sin(sqrt(abs((*ind)[i])));
	}

	return result;
}

int main(int argc, char** argv)
{
	int rank, size;
	double start, end;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    char func;
    int dim;
    double lowerBound;
    double upperBound;

    if (rank == 0)
	{
		do
		{
			printf("Select cost function (D - De Jong; S - Schwefel):\n");
    		scanf("%c", &func);
    	} while (func != 'D' && func != 'S');
    	
		do
		{
			printf("Choose dimension (1+):\n");
    		scanf("%d", &dim);
    	} while (dim < 1);
    	
		MPI_Bcast(&func, 1, MPI_CHAR, 0, MPI_COMM_WORLD);
		MPI_Bcast(&dim, 1, MPI_INT, 0, MPI_COMM_WORLD);
	}
	else
	{
		MPI_Bcast(&func, 1, MPI_CHAR, 0, MPI_COMM_WORLD);
		MPI_Bcast(&dim, 1, MPI_INT, 0, MPI_COMM_WORLD);
	}
	
	double (*costFunction)(int, Individual*);
	
	switch (func)
	{
		case 'D':
			costFunction = &DeJong;
			lowerBound = -5.12;
			upperBound = 5.11;
			break;
		case 'S':
			costFunction = &Schwefel;
			lowerBound = -512;
			upperBound = 511;
			break;
	}

    MPI_Barrier(MPI_COMM_WORLD);
	start = MPI_Wtime();
	
	SOMAParameters parameters(dim, 20, 100, 5, 0.11, 0.1, -1);
	initRandom(rank * parameters.Dimension * parameters.Population, argc, argv);
	Specimen spec(parameters.Dimension, lowerBound, upperBound);
	
	EvolutionaryAlgorithm* ea = new SOMAParallel(&parameters, spec, costFunction, rank, size);
	ea->ShowProgress(rank == 0);
	
	Individual* res = ea->GetBestSolution();
	
	if (rank == 0)
	{
		printf("\nBest individual cost: %f\n", res->GetCost());
		printf("Best individual:\n");
		
		for (int i = 0; i < dim; i++)
		{
			printf("\tx%d: %f\n", i, res->params[i]);
		}
	}

	delete ea;

	// Time measure and finish
    MPI_Barrier(MPI_COMM_WORLD);
	end = MPI_Wtime();
    
    if (rank == 0)
	{
    	printf("Elapsed time: %f ms\n", (end - start) * 1000);
	}
	
    MPI_Finalize();
	return 0;
}
