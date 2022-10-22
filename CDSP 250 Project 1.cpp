//Written by: Daniel Adewetan//
//CSDP 250 Project 1//
//Date: 10/17/2022//

#include<iostream> //Header file
#include"project.hpp"
using namespace std;


StudentList::StudentList() 
{
	head = nullptr;
}

void StudentList::appendNode(int num, double num2) //The function to append the node
{
	ListNode* newNode;
	ListNode* nodePtr;
	newNode = new ListNode;
	newNode->ID = num;
	newNode->GPA = num2;
	newNode->next = nullptr;

	if (!head) {
		head = newNode;
	}
	else
	{
		nodePtr = head;
		while (nodePtr->next)
			nodePtr = nodePtr->next;
		nodePtr->next = newNode;
	}
}

void StudentList::insertNode(int num, double num2) //the function to insert a node 
{
	ListNode* newNode;
	ListNode* nodePtr;
	ListNode* previousNode;

	newNode = new ListNode;
	newNode->ID = num;
	newNode->GPA = num2;

	if(!head)
	{
		head = newNode;
		
	}

	else
	{
		nodePtr = head;
		previousNode = NULL;

		while(nodePtr->ID < num && nodePtr != nullptr)
		{
			previousNode = nullptr;
			nodePtr = nodePtr->next;

			while (nodePtr->GPA < num2 && nodePtr != nullptr)
			{
				previousNode = nullptr;
				nodePtr = nodePtr->next;
			}
		
			if (previousNode == NULL)
			{
				head = newNode;
				newNode->next = nodePtr;
		
	        }
			else {
				previousNode->next = newNode;
				newNode->next = nodePtr;
			}
		}
	  }
}


void StudentList::deleteNode(int num) //the function to delete a node
{
	ListNode* nodePtr;
	ListNode* previousNode;

	if (!head) {
		return;
	}
	if (head->ID == num)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}

	else
	{
		nodePtr = head;
		while (nodePtr != nullptr && nodePtr->ID != num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;

			if (nodePtr)
			{
				previousNode->next = nodePtr->next;

			}
		}
	}
}



void StudentList::displayList() const //the function to display the list of nodes
{
	ListNode* nodePtr;
	nodePtr = head;
	while (nodePtr)
	{
		cout <<"ID: " <<nodePtr->ID << "    GPA: " <<nodePtr->GPA << endl;
		nodePtr = nodePtr->next;
	}
}
