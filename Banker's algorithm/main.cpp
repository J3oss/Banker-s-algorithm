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
	int** allocation_matrix = allocation_generation(no_of_resources, no_of_processes);
	//int** max_matrix = maxlist_generation(no_of_resources, no_of_processes,availblity_matrix);
	//int** request_matrix = requestlist_generation(no_of_resources, no_of_processes,max_matrix);
	//int** need_matrix = needlist_generation(no_of_resources, no_of_processes,max_matrix,request_matrix);
	#pragma endregion

	system("pause");
}