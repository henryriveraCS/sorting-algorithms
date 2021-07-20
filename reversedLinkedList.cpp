#include <iostream>
//#define arrSize 6

struct linkedItem
{
	int value;
	struct linkedItem *nextPtr;	
};

//used to create the linked list if given an array
void createLinkedList(struct linkedItem linkedList[], int arr[], int arrSize)
{
	//initialize the linked items first, iterate over it again to add pointer
	for(int i = 0; i <= arrSize; i++)
	{
		struct linkedItem e;
		e.value = arr[i];
		linkedList[i] = e;
	}

	//add the pointer now that we added everything
	for(int i = 0; i <= arrSize; i++)
	{
		//check if next item.value exists to add a pointer
		if(&linkedList[i+1])
		{
			linkedList[i].nextPtr = &linkedList[i+1];	
		}
	}
}

void printList(struct linkedItem linkedList[], int arrSize)
{
	for(int i = 0; i <= arrSize; i++)
	{
		struct linkedItem e = linkedList[i];
		if(e.value)
		{
			std::cout << e.value << ", ";
		}
	}
}

void reverseList(int arrSize)
{
	struct linkedItem linkedList[arrSize];
}

int main()
{
	int arrSize = 6;
	int arr[] = {10, 80, 30, 90, 40, 50, 70}; 
	struct linkedItem linkedList[arrSize];

	//create linked list
	createLinkedList(linkedList, arr, arrSize);

	std::cout << "ORIGINAL LIST: ";
	printList(linkedList, arrSize);
	
	return 0;
}

