#include <iostream>

void printArray(int arr[], int arrSize)
{
	for(int i=0; i<arrSize; i++){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

//used to swap 2 values
void swap(int* a, int* b)
{
	std::cout << "SWAPPING: " << *a << " AND " << *b << std::endl;
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int arr[], int arrSize)
{
	int i;
	int j;

	//iterate through the entire array
	for(i=0; i < arrSize; i++)
	{
		//iterate through array again (but keep track of lowest index with lowest_idx and swap if necessary)
		for(j=0; j < arrSize; j++)
		{
			//cout << "CURRENT AT: " << arr[j] << endl;
			//cout << "LOOKING AT: " << arr[j+1] << endl;
			// if current index greater than next index -> swap
			if(arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
				printArray(arr, arrSize);
				std::cout << std::endl;
			}
		}
	}
}

int main()
{
	std::cout << "BUBBLE SORT" << std::endl;

	//array info
	int arrSize = 7;
	int arr[arrSize] = {5, 1, 4, 2, 8, 3};
	
	//unorganized array:
	std::cout << "UNORGANIZED ARRAY: ";
	printArray(arr, arrSize);
	
	//run sort algorithm
	bubbleSort(arr, arrSize);

	//organized array
	std::cout << "FINAL ARRAY: ";
	printArray(arr, arrSize);

	return 0;
}
