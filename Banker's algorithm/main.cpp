#include "iostream"

#pragma region declarations
int** copy_matrix(int row, int column, int** matrix_to_copy);
int* copy_array(int column, int* array_to_copy);
void  print_all(int no_of_resources, int no_of_processes, int* available_array, int** max_matrix, int** allocation_matrix, int** need_matrix);
int** allocation_matrix_generation(int no_of_resources, int no_of_processes);
int** need_matrix_generation(int no_of_resources, int no_of_processes);
int** max_generation(int no_of_resources, int no_of_processes, int* availblity);
void print_matrix(const char* messange, int** matrix_to_print, int no_of_processes, int no_of_resources);
void print_array(const char* messange, int* array_to_print, int no_of_resources);
int* request_generator(int no_of_resources, int mapping_number, int** max_matrix);
void allocate(int mapping_number, int no_of_processes, int no_of_resources, int* request, int** allocation_matrix, int** max_matrix, int** need_matrix, int* availblity_matrix);
bool test(bool& kk, int mapping_number, int no_of_processes, int no_of_resources, int** allocation_matrix, int**max_matrix, int* availble, int* request, int** need_matrix);
#pragma endregion

int main()
{
	#pragma region PHASE1
	int no_of_processes = 0;
	int no_of_resources = 0;
	int* available_array;

	std::cout << "Please entre the following:" << std::endl;
	std::cout << "1) Number of resources:";
	std::cin >> no_of_resources;
	std::cout << "2) Number of processes:";
	std::cin >> no_of_processes;

	available_array = new int[no_of_resources];
	std::cout << "Please entre the available resources:" << std::endl;
	for (int i = 0; i < no_of_resources; i++)
	{
		std::cin >> available_array[i];
	}
	std::cout << std::endl;

	int** allocation_matrix = allocation_matrix_generation(no_of_resources, no_of_processes);
	int** max_matrix = max_generation(no_of_resources, no_of_processes, available_array);
	int** need_matrix = need_matrix_generation(no_of_resources, no_of_processes);
	#pragma endregion

	print_all(no_of_resources,no_of_processes,available_array,max_matrix,allocation_matrix,need_matrix);

	int mapping_number = 0;//maps user input of which process requests
	bool kk = false;//true means safe,false means unsafe

	while (true)
	{
		std::cin >> mapping_number;

		int* request = request_generator(no_of_resources, mapping_number, max_matrix);
		print_array("request:", request, no_of_resources);
		std::cout << std::endl;

		int** copy_allocation = copy_matrix(no_of_processes, no_of_resources, allocation_matrix);
		int** copy_need = copy_matrix(no_of_processes, no_of_resources, need_matrix);
		int* copy_availble = copy_array(no_of_resources, available_array);

		allocate(mapping_number, no_of_processes, no_of_resources, request, copy_allocation, max_matrix, copy_need, copy_availble);

		
		if (!test(kk, mapping_number, no_of_processes, no_of_resources, copy_allocation, max_matrix, copy_availble, request, copy_need))
		{
			request[0] = 0;
			request[1] = 0;
		}
		allocate(mapping_number, no_of_processes, no_of_resources, request, allocation_matrix, max_matrix, need_matrix, available_array);
		print_all(no_of_resources, no_of_processes, available_array, max_matrix, allocation_matrix, need_matrix);
		available_array[0] = 10;
		available_array [1] = 10;
	}
	system("pause");
}