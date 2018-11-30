#include "iostream"

int* user_input(int& no_of_resources, int& no_of_processes);
int** allocation_matrix_generation(int no_of_resources, int no_of_processes);
int** max_matrix_generation(int no_of_resources, int no_of_processes);
int** need_matrix_generation(int no_of_resources, int no_of_processes);
int** maxlist_generation(int no_of_resources, int no_of_processes, int* availblity);
int** requestlist_generation(int no_of_resources, int no_of_processes, int** max_list);
int** needlist_generation(int no_of_resources, int no_of_processes, int** max_list, int** request_list);
void allocate(int request_pointer, int allocation_pointer, int no_of_resources, int** request_list, int** allocation_matrix, int** max_list, int** max_matrix, int** need_list, int** need_matrix, int* availblity_matrix);
void test(int no_of_resources, int no_of_processes, int* availblity_matrix, int** max_matrix);

int main()
{
	#pragma region PHASE1
	//intializing number of prcesses,number of resources & availble matrix
	int no_of_processes = 0;
	int no_of_resources = 0;
	int* availblity_matrix = user_input(no_of_resources,no_of_processes);
	#pragma endregion

	#pragma region PHASE2
	//intializing allocation matrix,max matrix,request matrix & need matrix
	int** allocation_matrix = allocation_matrix_generation(no_of_resources, no_of_processes);
	int** max_matrix = max_matrix_generation(no_of_resources, no_of_processes);
	int** need_matrix = need_matrix_generation(no_of_resources, no_of_processes);

	std::cout << "max_matrix:" << std::endl;
	int** max_list = maxlist_generation(no_of_resources, no_of_processes,availblity_matrix);
	for (int i = 0; i < 2*no_of_processes; i++)
	{
		for (int j = 0; j < no_of_resources; j++)
		{
			std::cout << max_list[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "request_list:" << std::endl;
	int** request_list = requestlist_generation(no_of_resources, no_of_processes, max_list);
	for (int i = 0; i < 2 * no_of_processes; i++)
	{
		for (int j = 0; j < no_of_resources; j++)
		{
			std::cout << request_list[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "need_matrix:" << std::endl;
	int** need_list = needlist_generation(no_of_resources, no_of_processes, max_list, request_list);
	for (int i = 0; i < 2 * no_of_processes; i++)
	{
		for (int j = 0; j < no_of_resources; j++)
		{
			std::cout << need_list[i][j] << " ";
		}
		std::cout << std::endl;
	}


	#pragma endregion

	std::cout << "allocation_matrix:" << std::endl;
	allocate(1, 1, no_of_resources, request_list, allocation_matrix, max_list, max_matrix, need_list, need_matrix, availblity_matrix);

	for (int i = 0; i < no_of_processes; i++)
	{
		for (int j = 0; j < no_of_resources; j++)
		{
			std::cout << allocation_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "availblity_matrix:" << std::endl;
	for (int i = 0; i < no_of_resources; i++)
	{
		std::cout << availblity_matrix[i];
	}
	std::cout<<std::endl;

	std::cout << "test:" << std::endl;
	test(no_of_resources, no_of_processes, availblity_matrix, max_matrix);

	system("pause");
}