#include "iostream"

int* user_input(int& no_of_resources, int& no_of_processes)
{
	std::cout << "Please entre the following:" << std::endl;
	std::cout << "1) Number of resources:";
	std::cin >> no_of_resources;
	std::cout << "2) Number of processes:";
	std::cin >> no_of_processes;

	int* available = new int[no_of_resources];
	std::cout << "Please entre the available resources:" << std::endl;

	for (int i = 0; i < no_of_resources; i++)
	{
		std::cin >> available[i];
	}

	return available;
}