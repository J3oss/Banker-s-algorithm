#include "iostream"

void allocate(int request_pointer,int allocation_pointer,int no_of_resources,int** request_list, int** allocation_matrix, int** max_list, int** max_matrix, int** need_list, int** need_matrix, int* availblity_matrix)
{
	for (int i = 0; i < no_of_resources; i++)
	{
		allocation_matrix[allocation_pointer][i] = request_list[request_pointer][i];
		max_matrix[allocation_pointer][i] = max_list[request_pointer][i];
		need_matrix[allocation_pointer][i] = need_list[request_pointer][i];

		availblity_matrix[i] = availblity_matrix[i] - allocation_matrix[allocation_pointer][i];
	}

}

void test(int no_of_resources,int no_of_processes,int* availblity_matrix,int** max_matrix)
{
	int* sum = new int[no_of_resources];
	for (int j = 0; j < no_of_resources; j++)
	{
		sum[j] = 0;
	}

	for (int i = 0; i < no_of_resources; i++)
	{
		for (int j = 0; j < no_of_processes; j++)
		{
			sum[i] = sum[i]+ max_matrix[i][j];
		}
	}

	for (int i = 0; i < no_of_resources; i++)
	{
		std::cout << sum[i];
	}
	std::cout << std::endl;
}