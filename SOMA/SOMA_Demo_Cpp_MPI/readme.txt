This example of AllToOne SOMA is extracted from project of synthesis Artificial Neural networks and therefore some parts of the code may be considered as unnecessary complicated.

Compile using following command:
	mpic++ -std=c++11 SOMA_AllToOne.cpp -o SOMA_AllToOne

Run using following notations:
	mpirun -n number_of_processes SOMA_AllToOne random_number_generator B
	
	mpirun -n 4 SOMA_AllToOne MERSENNE B
	mpirun -n 4 SOMA_AllToOne LOGISTIC B
