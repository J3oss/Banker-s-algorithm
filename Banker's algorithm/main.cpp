#include "iostream"

#pragma region declarations
int** allocation_matrix_generation(int no_of_resources, int no_of_processes);
int** need_matrix_generation(int no_of_resources, int no_of_processes);
int** max_generation(int no_of_resources, int no_of_processes, int* availblity);
void print_matrix(const char* messange, int** matrix_to_print, int no_of_processes, int no_of_resources);
void print_array(const char* messange, int* array_to_print, int no_of_resources);
int* request_generator(int no_of_resources, int mapping_number, int** max_matrix);
void allocate(int mapping_number, int no_of_resources, int* request, int** allocation_matrix, int** max_matrix, int** need_matrix, int* availblity_matrix);
#pragma endregion

int main()
{
	#pragma region PHASE1
	int no_of_processes = 0;
	int no_of_resources = 0;
	int* available;

	std::cout << "Please entre the following:" << std::endl;
	std::cout << "1) Number of resources:";
	std::cin >> no_of_resources;
	std::cout << "2) Number of processes:";
	std::cin >> no_of_processes;
	available = new int[no_of_resources];
	std::cout << "Please entre the available resources:" << std::endl;
	for (int i = 0; i < no_of_resources; i++)
	{
		std::cin >> available[i];
	}
	std::cout << std::endl;
	int** allocation_matrix = allocation_matrix_generation(no_of_resources, no_of_processes);
	int** max_matrix = max_generation(no_of_resources, no_of_processes, available);
	int** need_matrix = need_matrix_generation(no_of_resources, no_of_processes);
	#pragma endregion

	print_array("availble:",available, no_of_resources);
	print_matrix("max:", max_matrix, no_of_processes, no_of_resources);
	print_matrix("allocation:", allocation_matrix, no_of_processes, no_of_resources);
	print_matrix("need:", need_matrix, no_of_processes, no_of_resources);

	int mapping_number = 0;//maps user input of which process requests

	int* request=request_generator(no_of_resources, mapping_number,max_matrix);
	print_array("request:", request, no_of_resources);

	allocate(mapping_number, no_of_resources, request, allocation_matrix, max_matrix, need_matrix, available);

	print_array("availble:", available, no_of_resources);
	print_matrix("max:", max_matrix, no_of_processes, no_of_resources);
	print_matrix("allocation:", allocation_matrix, no_of_processes, no_of_resources);
	print_matrix("need:", need_matrix, no_of_processes, no_of_resources);



	system("pause");
}