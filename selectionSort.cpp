#include <iostream>
using namespace std;

void printArray(int arr[], int arrSize)
{
	for(int i=0; i<arrSize; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

//used to swap 2 values
void swap(int* a, int* b)
{
	cout << "SWAPPING: " << *a << " AND " << *b << endl;
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int arr[], int arrSize)
{
	int i;
	int j;
	int lowest_idx;

	//iterate through the entire array
	for(i=0; i < arrSize; i++)
	{
		lowest_idx = i;
		//iterate through array again (but keep track of lowest index with lowest_idx and swap if necessary)
		for(j=i+1; j < arrSize; j++)
		{
			//cout << "CURRENT AT: " << arr[lowest_idx] << endl;
			//cout << "LOOKING AT: " << arr[j] << endl;
			//check if the current index is lower than the lowest_idx
			if(arr[j] < arr[lowest_idx])
			{
				//the new lowest index is the current index
				lowest_idx = j;				
			}
		}
		//swap around the current index with lowest_idx after it iterates through the array
		swap(&arr[lowest_idx], &arr[i]);
		/*
		cout << "CURRENT ARRAY: ";
		printArray(arr, arrSize);
		cout << endl;
		*/
	}
}

int main()
{
	//array info
	int arrSize = 7;
	int arr[arrSize] = {15, 62, 22, 71, 27, 86, 14};
	
	//unorganized array:
	cout << "UNORGANIZED ARRAY: ";
	printArray(arr, arrSize);
	
	//run sort algorithm
	selectionSort(arr, arrSize);

	//organized array
	cout << "FINAL ARRAY: ";
	printArray(arr, arrSize);

	return 0;
}
