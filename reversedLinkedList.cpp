#include <iostream>
//#define arrSize 6

class Node
{
	public:
		int data;
		Node *next;
};

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

void getLastNode(Node **prev_node, Node **last_node, Node **head)
{
	Node *current_node = *head;

	while(current_node->next)
	{
		//update prev node to keep track of node right before the last node
		if(current_node->next)
		{
			*prev_node = current_node;
		}
		current_node = current_node->next;	
		*last_node = current_node;
	}
}

void popNode(Node *node, Node **head)
{
	Node *prev_node;
	Node *next_node;
	Node *current_node = *head;
	if(head == NULL)
	{
		std::cout << "HEAD IS EMPTY\n";
		return;
	}

	while(current_node != node)
	{
		prev_node = current_node;
		current_node = current_node->next;	
	}
	//now that current_node = the node we want to remove -> update the ptr on prev node
	prev_node->next = current_node->next;
	//OPTIONAL PARAMETER, SHOULDNT MATTER SINCE current_node HAS NOTHING POINTING TO IT
	//current_node = NULL;
}

void reverseList(Node **reverseHead, Node **head)
{
	Node *last_node = *head;
	Node *prev_node = *head; 
	Node *c_node = *head;
	Node *new_head;

	//get the last node
	getLastNode(&prev_node, &last_node, head);

	//start reversing the list:
	while(c_node->next)
	{
		if(c_node->next)
		{
			std::cout << "\nNEW NODE LIST: ";
			printList(&new_head);
			std::cout << std::endl;
			std::cout << "\nOLD NODE LIST: ";
			printList(head);
			std::cout << "\nPREV NODE: " << prev_node->data << std::endl;

			last_node->next = prev_node;	
			appendNode(&new_head, last_node->data);

			prev_node->next = NULL;
			getLastNode(&prev_node, &last_node, head);
		}
	}

	//manually re-assign the first node in original head to new head
	std::cout << "\nRE-ASSIGNING FIRST TWO NODES: " << std::endl;
	appendNode(&new_head, c_node->data);
	popNode(c_node, head);

	std::cout << "\n\nREVERSED NODE LIST: ";
	printList(&new_head);
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
	
	std::cout << "ORIGINAL NODE LIST: ";
	printList(&head);

	//reverse the list
	Node *reverseHead = new Node();
	reverseList(&reverseHead, &head);

	
	return 0;
}

