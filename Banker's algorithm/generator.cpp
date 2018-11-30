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
int** max_matrix_generation(int no_of_resources, int no_of_processes)
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
int** maxlist_generation(int no_of_resources, int no_of_processes, int* availblity)
{
	int** a = new int*[2*no_of_processes];
	for (int i = 0; i < 2*no_of_processes; ++i)
		a[i] = new int[no_of_resources];

	for (int i = 0; i < 2*no_of_processes; i++)
	{
		for (int j = 0; j < no_of_resources; j++)
		{
			a[i][j] = std::rand() % (availblity[j]*1/3)+1;
		}
	}
	return a;
}
int** requestlist_generation(int no_of_resources, int no_of_processes, int** max_list)
{
	int** a = new int*[2 * no_of_processes];
	for (int i = 0; i < 2 * no_of_processes; ++i)
		a[i] = new int[no_of_resources];

	for (int i = 0; i < 2 * no_of_processes; i++)
	{
		for (int j = 0; j < no_of_resources; j++)
		{
			a[i][j] = std::rand() % max_list[i][j];
		}
	}
	return a;
}
int** needlist_generation(int no_of_resources, int no_of_processes, int** max_list, int** request_list)
{
	int** a = new int*[2 * no_of_processes];
	for (int i = 0; i < 2 * no_of_processes; ++i)
		a[i] = new int[no_of_resources];

	for (int i = 0; i < 2 * no_of_processes; i++)
	{
		for (int j = 0; j < no_of_resources; j++)
		{
			a[i][j] = max_list[i][j]-request_list[i][j];
		}
	}
	return a;
}