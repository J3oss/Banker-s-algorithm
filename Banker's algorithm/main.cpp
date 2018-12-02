#include "iostream"

int** max_generation(int no_of_resources, int no_of_processes, int** availblity) //defines 2D array and fill it with random numbers
{
	int** a = new int*[no_of_processes];
	for (int i = 0; i < no_of_processes; ++i)
	{
		a[i] = new int[no_of_resources];
		for (int j = 0; j < no_of_resources; j++)
			a[i][j] = std::rand() % (availblity[0][j]) + 1;
	}
	return a;
}
int** matrix_generation(int no_of_resources, int no_of_processes) //defines 2D array and fill it with zeros
{
	int** a = new int*[no_of_processes];
	for (int i = 0; i < no_of_processes; ++i)
	{
		a[i] = new int[no_of_resources];
		for (int j = 0; j < no_of_resources; j++)
			a[i][j] = 0;
	}
	return a;
}
int** copy_matrix(int row, int column, int** matrix_to_copy)
{
	int** a = new int*[row];
	for (int i = 0; i < row; ++i)
		a[i] = new int[column];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			a[i][j] = matrix_to_copy[i][j];
	}
	return a;
}
void  print_matrix(const char* messange, int** matrix_to_print, int no_of_processes, int no_of_resources)
{
	std::cout << messange << std::endl;
	int** a = matrix_to_print;
	for (int i = 0; i < no_of_processes; i++)
	{
		std::cout << "| ";
		for (int j = 0; j < no_of_resources; j++)
			std::cout << a[i][j] << " ";
		std::cout << "|" << std::endl;
	}
}
void  print_all(int no_of_resources, int no_of_processes, int** available_array, int** max_matrix, int** allocation_matrix, int** need_matrix)
{
	print_matrix("availble:", available_array, 1, no_of_resources);
	print_matrix("max:", max_matrix, no_of_processes, no_of_resources);
	print_matrix("allocation:", allocation_matrix, no_of_processes, no_of_resources);
	print_matrix("need:", need_matrix, no_of_processes, no_of_resources);
	std::cout << std::endl;
}

void allocate(int mapping_number, int no_of_processes, int no_of_resources, int** request, int** allocation_matrix, int** max_matrix, int** need_matrix, int** availblity_matrix)
{
	for (int i = 0; i < no_of_processes; i++)
	{
		for (int j = 0; j < no_of_resources; j++)
		{
			allocation_matrix[mapping_number][j] = request[0][j];
			need_matrix[i][j] = max_matrix[i][j] - allocation_matrix[i][j];
			availblity_matrix[0][j] = availblity_matrix[0][j] - allocation_matrix[i][j];
		}
	}
}
bool test(int mapping_number, int no_of_processes, int no_of_resources, int** allocation_matrix, int**max_matrix, int** availble, int** request, int** need_matrix,int** &finish_sequence)
{
	for (int i = 0; i < no_of_resources; i++)
	{
		if (availble[0][i]<0)
		{
			std::cout << "system doesn't contain free resources" << std::endl;
			std::cout << "Request is rejected" << std::endl;
			return false;
		}
	}

	int safe = 0;
	int counter = 1;
	int** finish = matrix_generation(1,no_of_processes);

	for (int i = 0; i < no_of_processes; i++)//worst case scenario
	{
		for (int i = 0; i < no_of_processes; i++)
		{
			if (finish[i][0] == 0) //if finish is false
			{
				for (int j = 0; j < no_of_resources; j++)
				{
					if (need_matrix[i][j] <= availble[0][j])
						safe++;
				}
				if (safe == no_of_resources)// if allocation of process is less than availble
				{
					for (int j = 0; j < no_of_resources; j++)
						availble[0][j] = availble[0][j] + allocation_matrix[i][j];
					finish[i][0] = counter;
					counter++;
					safe = 0;
				}
			}
		}
	}

	for (int i = 0; i < no_of_processes; i++)
	{
		if (finish[i] == 0)
		{
			std::cout << "Request makes system unsafe !!" << std::endl;
			std::cout << "Request is rejected !!" << std::endl;
			finish_sequence = finish;
			return false;
		}
	}

	std::cout << "Request is accepted and added !" << std::endl;
	std::cout << std::endl;
	std::cout << "System after request is added:" << std::endl;
	std::cout << std::endl;
	finish_sequence = finish;
	std::cout << std::endl;
	return true;
}

int main()
{
	int   no_of_processes = 0; //user defined , represents number of processes in the system
	int   no_of_resources = 0; //user defined , represents number of resources in the system
	int   mapping_number = 0;  //user defined , which represent what process is requested
	int** available_array;     //user defined , represents amount of each resources in the system
	int** finish_sequence = 0;

	std::cout << "Please entre the following:" << std::endl; //User inputs
	std::cout << "1) Number of resources:";
	std::cin  >> no_of_resources;
	std::cout << "2) Number of processes:";
	std::cin  >> no_of_processes;
	available_array = new int*[no_of_resources];
	for (int i = 0; i < 1; ++i)
		available_array[i] = new int[no_of_resources];
	std::cout << "Please entre system's resources:" << std::endl;
	for (int i = 0; i < no_of_resources; i++)
		std::cin >> available_array[0][i];
	std::cout << std::endl;

	int** allocation_matrix = matrix_generation(no_of_resources, no_of_processes); //Define all arrays
	int** need_matrix = matrix_generation(no_of_resources, no_of_processes);
	int** max_matrix = max_generation(no_of_resources, no_of_processes, available_array);
	int** availble_from_start = copy_matrix(1,no_of_resources, available_array);
	
	print_all(no_of_resources, no_of_processes, available_array, max_matrix, allocation_matrix, need_matrix);

	while (true)
	{
		start:
		std::cout << "Please entre a process's number to generate its request:";
		std::cin >> mapping_number; //User command
		std::cout << std::endl;

		if (!(0>mapping_number || mapping_number>(no_of_processes-1)))
		{
			int** request = new int*[no_of_resources]; //Generate user request and print it
			for (int i = 0; i < 1; ++i)
				request[i] = new int[no_of_resources];
			for (int i = 0; i < no_of_resources; i++)
				request[0][i] = std::rand() % (max_matrix[mapping_number][i] + 1) + 0;
			print_matrix("Request:", request, 1, no_of_resources);
			std::cout << std::endl;

			int** copy_allocation = copy_matrix(no_of_processes, no_of_resources, allocation_matrix);//Make copies
			int** copy_need = copy_matrix(no_of_processes, no_of_resources, need_matrix);
			int** copy_availble = copy_matrix(1, no_of_resources, available_array);

			allocate(mapping_number, no_of_processes, no_of_resources, request, copy_allocation, max_matrix, copy_need, copy_availble);//allocate in copies

			if (!test(mapping_number, no_of_processes, no_of_resources, copy_allocation, max_matrix, copy_availble, request, copy_need,finish_sequence))//result of test
			{
				for (int i = 0; i < no_of_resources; i++) //if test determines that request makes system unsafe,system deletes the request
					request[0][i] = 0;
			}

			allocate(mapping_number, no_of_processes, no_of_resources, request, allocation_matrix, max_matrix, need_matrix, available_array);//allocate in real

			print_all(no_of_resources, no_of_processes, available_array, max_matrix, allocation_matrix, need_matrix);

			available_array = copy_matrix(1, no_of_resources, availble_from_start);//reset availble array
		}
		else
		{
			std::cout << "Invalid process number !!!"<<std::endl;
			goto start;
		}
		}
		
	system("pause");
}