#include "iostream"

#pragma region declarations
int* user_input(int& no_of_resources, int& no_of_processes);
int** allocation_matrix_generation(int no_of_resources, int no_of_processes);
int** max_matrix_generation(int no_of_resources, int no_of_processes);
int** need_matrix_generation(int no_of_resources, int no_of_processes);
int** maxlist_generation(int no_of_resources, int no_of_processes, int* availblity);
int** requestlist_generation(int no_of_resources, int no_of_processes, int** max_list);
int** needlist_generation(int no_of_resources, int no_of_processes, int** max_list, int** request_list);
void allocate(int request_pointer, int allocation_pointer, int no_of_resources, int** request_list, int** allocation_matrix, int** max_list, int** max_matrix, int** need_list, int** need_matrix, int* availblity_matrix);
void test(int no_of_resources, int no_of_processes, int* availblity_matrix, int** max_matrix);
void print_list(const char* messange, int** list_to_print, int no_of_processes, int no_of_resources);
void print_matrix(const char* messange, int** matrix_to_print, int no_of_processes, int no_of_resources);
void print_availble(int** availblity_matrix, int no_of_resources);
#pragma endregion

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

	int** max_list = maxlist_generation(no_of_resources, no_of_processes,availblity_matrix);
	int** request_list = requestlist_generation(no_of_resources, no_of_processes, max_list);
	int** need_list = needlist_generation(no_of_resources, no_of_processes, max_list, request_list);

	//printing generated function
	print_list("max list:",max_list,no_of_processes,no_of_resources);
	print_list("request list:", request_list, no_of_processes, no_of_resources);
	print_list("need list:", need_list, no_of_processes, no_of_resources);
	#pragma endregion

	allocate(0, 0, no_of_resources, request_list, allocation_matrix, max_list, max_matrix, need_list, need_matrix, availblity_matrix);
	allocate(1, 1, no_of_resources, request_list, allocation_matrix, max_list, max_matrix, need_list, need_matrix, availblity_matrix);
	allocate(2, 2, no_of_resources, request_list, allocation_matrix, max_list, max_matrix, need_list, need_matrix, availblity_matrix);
	allocate(3, 3, no_of_resources, request_list, allocation_matrix, max_list, max_matrix, need_list, need_matrix, availblity_matrix);

	print_matrix("max", max_matrix,no_of_processes,no_of_resources);
	print_matrix("allocation", allocation_matrix, no_of_processes, no_of_resources);
	print_matrix("need", need_matrix, no_of_processes, no_of_resources);

	std::cout << "test:" << std::endl;
	test(no_of_resources, no_of_processes, availblity_matrix, need_matrix);

	system("pause");
}