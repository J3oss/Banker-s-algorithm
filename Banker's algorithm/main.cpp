#include "iostream"

int* user_input(int& no_of_resources, int& no_of_processes);
int** allocation_generation(int no_of_resources, int no_of_processes);
int** maxlist_generation(int no_of_resources, int no_of_processes, int* availblity);
int** requestlist_generation(int no_of_resources, int no_of_processes, int** max_list);
int** needlist_generation(int no_of_resources, int no_of_processes, int** max_list, int** request_list);

int main()
{
	#pragma region PHASE1
	//intializing number of prcesses,number of resources & availble matrix
	int no_of_processes = 0;
	int no_of_resources = 0;
	int* availblity_matrix = user_input(no_of_resources, no_of_processes);
	#pragma endregion

	#pragma region PHASE2
	//intializing allocation matrix,max matrix,request matrix & need matrix
	std::cout << "allocation_matrix:" << std::endl;
	int** allocation_matrix = allocation_generation(no_of_resources, no_of_processes);
	for (int i = 0; i < no_of_processes; i++)
	{
		for (int j = 0; j < no_of_resources; j++)
		{
			std::cout << allocation_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "max_matrix:" << std::endl;
	int** max_matrix = maxlist_generation(no_of_resources, no_of_processes,availblity_matrix);
	for (int i = 0; i < 2*no_of_processes; i++)
	{
		for (int j = 0; j < no_of_resources; j++)
		{
			std::cout << max_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "request_matrix:" << std::endl;
	int** request_matrix = requestlist_generation(no_of_resources, no_of_processes,max_matrix);
	for (int i = 0; i < 2 * no_of_processes; i++)
	{
		for (int j = 0; j < no_of_resources; j++)
		{
			std::cout << request_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "need_matrix:" << std::endl;
	int** need_matrix = needlist_generation(no_of_resources, no_of_processes,max_matrix,request_matrix);
	for (int i = 0; i < 2 * no_of_processes; i++)
	{
		for (int j = 0; j < no_of_resources; j++)
		{
			std::cout << need_matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
	#pragma endregion

	system("pause");
}