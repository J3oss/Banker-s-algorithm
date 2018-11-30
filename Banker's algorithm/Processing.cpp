#include "iostream"

void allocate(int mapping_number,int no_of_resources,int* request,int** allocation_matrix,int** max_matrix,int** need_matrix,int* availblity_matrix)
{
	for (int i = 0; i < no_of_resources; i++)
	{
		allocation_matrix[mapping_number][i] = request[i];
		need_matrix[mapping_number][i] = max_matrix[mapping_number][i] - allocation_matrix[mapping_number][i];
		availblity_matrix[i] = availblity_matrix[i] - allocation_matrix[mapping_number][i];
	}
}

void test()
{
	
}