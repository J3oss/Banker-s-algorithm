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

void test(int no_of_resources,int no_of_processes,int* availblity_matrix,int** need_matrix)
{
	int true_counter=0;
	int* sum = new int[no_of_resources];
	for (int i = 0; i < no_of_resources; i++)
	{
		sum[i] = 0;
	}

	for (int i = 0; i < no_of_resources; i++)
	{
		for (int j = 0; j < no_of_processes; j++)
		{
			sum[i] = sum[i]+ need_matrix[j][i];
		}
	}
	
	for (int i = 0; i < no_of_resources; i++)
	{
		if (availblity_matrix[i]>=sum[i])
		{
			true_counter++;
		}
	}
	if (true_counter == no_of_resources)
	{
		std::cout << "system is in safe state"<<std::endl;
	}
	else
	{
		std::cout << "system is in unsafe state" << std::endl;
		//remove last added process
	}
}