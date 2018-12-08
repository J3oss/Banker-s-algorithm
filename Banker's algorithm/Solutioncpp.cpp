#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int pn;
int rn;
int nRequests;

int* available;

int* finish;

int** alloc;
int** max;
int** need;
int* requests;
int* deAllocation;

int** copyAllocate;
int** copyNeed;
int* copyAvailable;

void getInputs()
{
	cout << "Please enter the number of processes: ";
	cin >> pn;
	cout << endl;
	cout << "Please enter the number of resources: ";
	cin >> rn;
	cout << endl;
	cout << "Please enter the number of requests: ";
	cin >> nRequests;
	cout << endl;

	available = new  int[rn];

	requests = new int[rn];

	deAllocation = new int[rn];

	finish = new int[pn];

	for (int i = 0; i < rn; i++)
	{
		cout << "Please enter the number of resource no." << i + 1 << " : ";
		cin >> available[i];
	}
	cout << endl;



	for (int i = 0; i < pn; i++)
	{
		finish[i] = false;
	}

	alloc = new  int*[pn];
	for (int i = 0; i < pn; i++)
	{
		alloc[i] = new  int[rn];
	}

	max = new  int*[pn];
	for (int i = 0; i < pn; i++)
	{
		max[i] = new  int[rn];
	}

	need = new  int*[pn];
	for (int i = 0; i < pn; i++)
	{
		need[i] = new  int[rn];
	}

	/*requests = new  int*[pn*3];
	for ( int i = 0; i < pn*3; i++)
	{
		requests[i] = new  int[rn];
	}*/
}

void fillMax()
{
	srand(time(0));
	for (int i = 0; i < pn; i++)
	{
		for (int j = 0; j < rn; j++)
		{
			max[i][j] = (rand() % available[j]);
		}
	}

}

void printMax(int** max)
{
	cout << "Max:\n";
	for (int i = 0; i < pn; i++)
	{
		cout << "P" << i << " ";
		for (int j = 0; j < rn; j++)
		{
			cout << max[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void fillAlloc()
{

	for (int i = 0; i < pn; i++)
	{
		for (int j = 0; j < rn; j++)
		{

			alloc[i][j] = 0;

		}
	}

}

void calcNeed()
{
	for (int i = 0; i < pn; i++)
	{
		for (int j = 0; j < rn; j++)
		{
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
}

void getReq(int processNum)
{
	for (int i = 0; i < pn; i++)
	{
		for (int j = 0; j < rn; j++)
		{
			requests[j] = (rand() % need[processNum][j]);
		}
	}
}

void printReq()
{
	cout << "Request: ";
	for (int i = 0; i < rn; i++)
	{
		cout << requests[i] << " ";
	}
	cout << endl << endl;
}

int** copy2DMatrix(int** matrix_to_copy)
{
	int** copy = new int*[pn];
	for (int i = 0; i < pn; i++)
	{
		copy[i] = new  int[rn];
	}

	for (int i = 0; i < pn; i++)
	{
		for (int j = 0; j < rn; j++)
		{
			copy[i][j] = matrix_to_copy[i][j];
		}
	}
	return copy;
}

int* copy1DMatrix(int* mat)
{
	int* copy = new int[rn];
	for (int i = 0; i < rn; i++)
	{
		copy[i] = mat[i];
	}
	return copy;
}

void allocate(int** alloc, int** need, int* available, int processNum)
{
	for (int i = 0; i < rn; i++)
	{
		available[i] -= requests[i];
		alloc[processNum][i] += requests[i];
		need[processNum][i] -= requests[i];
	}
}

void deAllocate(int processNum)
{
	for (int i = 0; i < pn; i++)
	{
		for (int j = 0; j < rn; j++)
		{
			deAllocation[j] = (rand() % (alloc[processNum][j] + 1));
		}
	}

	for (int i = 0; i < rn; i++)
	{
		available[i] += deAllocation[i];
		alloc[processNum][i] -= deAllocation[i];
		need[processNum][i] += deAllocation[i];
	}
}

bool test()
{

	for (int i = 0; i < rn; i++)
	{
		if (requests[i] > available[i])
		{
			cout << "ERROR: Request more than available resources\n\n";
			return false;
		}
	}

	int count = 1;
	for (int i = 0; i < pn; i++)
	{
		for (int j = 0; j < pn; j++)
		{
			if (finish[j] == 0)
			{
				for (int k = 0; k < rn; k++)
				{

					if (copyNeed[j][k] > copyAvailable[k])
					{
						cout << "ERROR: P" << j << " must wait";
						finish[j] = 0;
						cout << "\n\n";
						break;
					}
					else
					{
						if (k == rn - 1)
						{
							for (int z = 0; z < rn; z++)
							{
								copyAvailable[z] += copyAllocate[j][z];
							}
							finish[j] = count++;
						}
						//finish[j] = 1;
					}

				}
			}
		}
	}
	for (int i = 0; i < pn; i++)
	{
		if (finish[i] == 0)
		{
			cout << "ERROR: System is unsafe\n\n";
			return false;
		}
	}
	cout << "System is safe\n\n";

	return true;
}

void printAll()
{
	cout << "	Alloc		Need		Available\n";
	for (int i = 0; i < pn; i++)
	{
		cout << "P" << i << "	";
		for (int j = 0; j < rn; j++)
		{
			cout << alloc[i][j] << " ";
		}
		cout << "		";
		for (int j = 0; j < rn; j++)
		{
			cout << need[i][j] << " ";
		}
		cout << "		";
		if (i == 0)
		{
			for (int j = 0; j < rn; j++)
			{
				cout << available[j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

void printFinish()
{
	cout << "Sequence of execution: ";
	for (int i = 0; i < pn; i++)
	{
		cout << "P" << i << ": ";
		cout << finish[i] << ", ";
	}
	cout << endl << endl;
}

void printDeAllocation(int processNumber)
{
	cout << "Deallocate P" << processNumber << " by: ";
	for (int i = 0; i < rn; i++)
	{
		cout << deAllocation[i] << " ";
	}
	cout << "\n\n";
}


void main()
{
	getInputs();
	int processNumber;
	fillMax();
	fillAlloc();
	calcNeed();

	printMax(max);
	printAll();

	cout << "---------------------------------------------------------------------\n";

	srand(time(0));

	for (int count = 0; count < nRequests; count++)
	{
		processNumber = rand() % pn;
		getReq(processNumber);
		cout << "P" << processNumber << " "; printReq();

		copyAllocate = copy2DMatrix(alloc);
		copyNeed = copy2DMatrix(need);
		copyAvailable = copy1DMatrix(available);
		allocate(copyAllocate, copyNeed, copyAvailable, processNumber);

		if (test())
		{
			allocate(alloc, need, available, processNumber);
			printAll();
			printFinish();
			if (count != nRequests - 1)
			{
				deAllocate(processNumber);
				printDeAllocation(processNumber);
			}

		}

		cout << "------------------------------------" << count + 1 << "---------------------------------\n";

	}
}
