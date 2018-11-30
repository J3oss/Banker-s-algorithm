#include "iostream"

void print_matrix(const char* messange, int** matrix_to_print, int no_of_processes, int no_of_resources)
{
	std::cout << messange << std::endl;
	int** a = matrix_to_print;

	for (int i = 0; i < no_of_processes; i++)
	{
		for (int j = 0; j < no_of_resources; j++)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void print_array(const char* messange, int* array_to_print,int no_of_resources)
{
	std::cout << messange << std::endl;
	for (int i = 0; i < no_of_resources; i++)
	{
		std::cout << array_to_print[i] << " ";
	}
	std::cout << std::endl;
}