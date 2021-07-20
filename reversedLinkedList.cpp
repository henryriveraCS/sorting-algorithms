#include <iostream>
//#define arrSize 6

class Node
{
	public:
		int data;
		Node *next;
};

/*
void appendAfter(Node *prev_node, int new_data)
{
	if(prev_node == NULL)
	{
		std::cout << "PREVIOS NODE CANNOT BE NULL \n";
		return;
	}
	//while there is a node -> keep going until there isn't so we can add new node with value new_data
	Node new_node;
	new_node->data = new_data;
	prev_node->next = new_node;
}
*/

//this will append to end of linked list
void appendNode(Node **head, int new_data)
{
	Node *new_node = new Node();
	new_node->data = new_data;
	new_node->next = NULL;
	
	//pointer used to get the last node currently in linked list
	Node *last_node = *head;
	
	//check if head node is empty -> if it does make the new node the head
	if(*head == NULL)
	{
		*head = new_node;
		return;
	}

	//otherwise iterate through linked list and get last node then append new node
	while(last_node->next != NULL)
	{
		last_node = last_node->next;
	}

	last_node->next = new_node;
	return;
}

void printList(Node **head)
{
	Node *c_node = *head;
	while(c_node != NULL)
	{
		std::cout << c_node->data << ", ";
		c_node = c_node->next;
	}	
}

void createLinkedList(Node **head, int arr[], int arrSize)
{
	for(int i = 0; i <= arrSize; i++)
	{
		appendNode(head, arr[i]);
	}
}

int main()
{
	int arrSize = 6;
	int arr[] = {10, 80, 30, 90, 40, 50, 70}; 

	//initialize head of node
	Node *head = NULL;
	//create linked list
	createLinkedList(&head, arr, arrSize);

	printList(&head);
	
	return 0;
}

