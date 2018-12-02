#include "iostream"

void  print_matrix(const char* messange, int** matrix_to_print, int no_of_processes, int no_of_resources)
{
	std::cout << messange << std::endl;
	int** a = matrix_to_print;

	for (int i = 0; i < no_of_processes; i++)
	{
		std::cout << "| ";
		for (int j = 0; j < no_of_resources; j++)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << "|" << std::endl;
	}
}

void  print_array(const char* messange, int* array_to_print,int no_of_resources)
{
	std::cout << messange << std::endl;
	std::cout << "| ";
	for (int i = 0; i < no_of_resources; i++)
	{
		std::cout << array_to_print[i] << " ";
	}
	std::cout <<"|"<< std::endl;
}

int** copy_matrix(int row,int column,int** matrix_to_copy)
{
	int** a = new int*[row];
	for (int i = 0; i < row; ++i)
		a[i] = new int[column];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			a[i][j] = matrix_to_copy[i][j];
		}
	}

	return a;
}

int* copy_array(int column, int* array_to_copy)
{
	int* a = new int[column];

	for (int i = 0; i < column; i++)
	{
		a[i] = array_to_copy[i];
	}

	return a;
}

void  print_all(int no_of_resources, int no_of_processes, int* available_array, int** max_matrix, int** allocation_matrix, int** need_matrix)
{
	print_array("availble:", available_array, no_of_resources);
	print_matrix("max:", max_matrix, no_of_processes, no_of_resources);
	print_matrix("allocation:", allocation_matrix, no_of_processes, no_of_resources);
	print_matrix("need:", need_matrix, no_of_processes, no_of_resources);
}
