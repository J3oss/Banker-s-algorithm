#include "iostream"

//define arrays and fill zeros
int** allocation_matrix_generation(int no_of_resources, int no_of_processes)
{
	int** a = new int*[no_of_processes];
	for (int i = 0; i < no_of_processes; ++i)
		a[i] = new int[no_of_resources];

	for (int i = 0; i < no_of_processes; i++)
	{
		for (int j = 0; j < no_of_resources; j++)
		{
			a[i][j] = 0;
		}
	}

	return a;
}
int** need_matrix_generation(int no_of_resources, int no_of_processes)
{
	int** a = new int*[no_of_processes];
	for (int i = 0; i < no_of_processes; ++i)
		a[i] = new int[no_of_resources];

	for (int i = 0; i < no_of_processes; i++)
	{
		for (int j = 0; j < no_of_resources; j++)
		{
			a[i][j] = 0;
		}
	}

	return a;
}

//define arrays and fill with random numbers
int** max_generation(int no_of_resources, int no_of_processes, int* availblity)
{
	int** a = new int*[no_of_processes];
	for (int i = 0; i < no_of_processes; ++i)
		a[i] = new int[no_of_resources];

	for (int i = 0; i < no_of_processes; i++)
	{
		for (int j = 0; j < no_of_resources; j++)
		{
			a[i][j] = std::rand() % (availblity[j])+1;
		}
	}
	return a;
}
int* request_generator(int no_of_resources,int mapping_number, int** max_matrix)
{
	int* a = new int[no_of_resources];
	for (int i = 0; i < no_of_resources; i++)
	{
			a[i] = std::rand() % (max_matrix[mapping_number][i]+1)+0;
	}
	return a;
}