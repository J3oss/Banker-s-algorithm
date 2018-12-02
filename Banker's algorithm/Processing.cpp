#include "iostream"

void allocate(int mapping_number, int no_of_processes, int no_of_resources,int* request,int** allocation_matrix,int** max_matrix,int** need_matrix,int* availblity_matrix)
{
	for (int i = 0; i < no_of_processes; i++)
	{
		for (int j = 0; j < no_of_resources; j++)
		{
			allocation_matrix[mapping_number][j] = request[j];
			need_matrix[i][j] = max_matrix[i][j] - allocation_matrix[i][j];
			availblity_matrix[j] = availblity_matrix[j] - allocation_matrix[i][j];
		}
	}
}

bool test(bool& kk,int mapping_number,int no_of_processes,int no_of_resources,int** allocation_matrix,int**max_matrix,int* availble,int* request,int** need_matrix)
{
	for (int i = 0; i < no_of_resources; i++)
	{
		if (availble[i]<0)
		{
			std::cout << "system doesn't contain free resources" << std::endl;
			std::cout << "Request is rejected" << std::endl;
			return false;
		}
	}
	int safe = 0;
	int counter = 1;
	int cc = 0;
	int* finish = new int[no_of_resources];

	for (int i = 0; i < no_of_resources; i++)
	{
		finish[i] = 0;
	}



	for (int i = 0; i < no_of_processes; i++)//worst case scenario
	{
		for (int i = 0; i < no_of_processes; i++)
		{
			if (finish[i] == 0) //if finish is false
			{
				for (int j = 0; j < no_of_resources; j++)
				{
					if (need_matrix[i][j] <= availble[j])
					{
						safe++;
					}
				}

				if (safe == no_of_resources)// if allocation of process is less than availble
				{
					for (int j = 0; j < no_of_resources; j++)
					{
						availble[j] = availble[j] + allocation_matrix[i][j];
					}
					finish[i] = counter;
					counter++;
					safe = 0;
				}
			}
		}
	}
	

	for (int i = 0; i < no_of_processes; i++)
	{
		if (finish[i]==0)
		{
			std::cout << "Request makes system unsafe" << std::endl;
			std::cout << "Request is rejected" << std::endl;
			return false;
		}
	}
		std::cout << "Request leaves system safe" << std::endl;
		std::cout << "Request is accepted and added" << std::endl;
		return true;
}