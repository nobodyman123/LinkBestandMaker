// PapasLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "windows.h"

typedef struct LinkedListNode { //struct for node in a linked list
	const char * url; //must have value (url)
	LinkedListNode * next; //and pointer to next node in list
} NODE, *PNODE;

PNODE create_node(const char* url) {
	PNODE n =(PNODE)malloc(sizeof(NODE));
	ZeroMemory(n, sizeof(NODE));
	n->url = url; 
	return n; 
}


typedef struct LinkedList {
	PNODE First;
	PNODE Last;

	void AddNode(const char* url)
	{
		PNODE newNode = create_node(url); 
		if(!Last) {
			First=Last=newNode;
		} else
		{
			Last->next=newNode;
			Last=Last->next;
		}
	}

	void Print()
	{
		PNODE node = First;
		int nodenumber=1;
		do
		{
			printf("The URL of node %d = %s\n", nodenumber++, node->url);
			node=node->next;
		} while (node);
	}

	void Free()
	{
		PNODE node = First;
		while(node)
		{
			PNODE current = node;
			node=node->next;
			free(current);
		}
	}
} NODELIST;



int main() {
	NODELIST list;
	list.First=list.Last=NULL;

	list.AddNode("https://www.google.com");
	list.AddNode("https://devdocs.io/c/language/scope");

	list.Print();

	list.Free();
	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
