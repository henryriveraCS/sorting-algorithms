#include <iostream>

/*
move pivot to end
move values less than pivot to left
move values more than pivot to right
our pivot should now be in the correct location
sort arr(less than pivot) and sort arr(more than pivot)
*/

void printArray(int arr[], int arrSize)
{
	for(int i=0; i<=arrSize; i++){
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

int partition(int arr[], int arrSize, int low, int high)
{
	int pivot = arr[high];
	int i = low-1; //used to keep track of elements less than pivot
	for(int j = low; j <= high; j++)
	{
		if(arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[high]); //swap out to the right of i and replace with our pivot(high)
	return (i+1); //everything should be sorted around our pivot (i+1) so return this position
}

void quickSort(int arr[], int arrSize, int low, int high)
{
	if(low < high)
	{
		int pi = partition(arr, arrSize, low, high);
		std::cout << "PARTION: " << pi << std::endl;

		//sort array higher than pivot
		quickSort(arr, arrSize, pi+1, high);
		//sort array lesser than pivot
		quickSort(arr, arrSize, low, pi-1);
	}
}

int main()
{
	

	int arrSize = 6;
	int arr[arrSize] = {10, 80, 30, 90, 40, 50, 70};

	std::cout << "UNORGANIZED ARRAY: ";
	printArray(arr, arrSize);

	int low = 0;
	int high = arrSize;

	quickSort(arr, arrSize, low , high);

	std::cout << "FINAL ARRAY: ";
	printArray(arr, arrSize);

	return 0;
}

