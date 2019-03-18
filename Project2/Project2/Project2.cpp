// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "windows.h"

typedef struct LinkedListNode { //struct for node in a linked list
	const char * url; //must have value (url)
	LinkedListNode * next; //and pointer to next node in list
} node; //typedef as node for easy use

node* create_node() { //function to creat LinkedListNode
	node* n; //create pointer to struct node
	n = (node*)malloc(sizeof(node)); //alloc some memory for node
	ZeroMemory(n, sizeof(node)); //clear memory for node (so next would be NULL instead of unintialised)
	return n; //return node
	
}

node* add_list_item(node* lNode,char* url) {
	node* item = lNode;
	item->url = url;
	item->next = create_node();
}

int main() {

	node* n1 = create_node();
	n1->url = "https://www.google.com";
	n1->next = create_node();
	n1->next->url = "https://devdocs.io/c/language/scope";
	n1->next->next = create_node();
	
	//testing url and next vars of n1 and n2
	printf("The URL of node 1 = %s\n", n1->url);
	printf("The URL of node 2 = %s\n", n1->next->url);
	printf("And the next node in the list is %p\n", n1->next);
	printf("The next node after node 2 is %p\n", n1->next->next);
	printf("node 3 URL: %s\n", n1->next->next->url);
	printf("node 3 pointer: %p\n", n1->next->next->next);

	//freeing memory allocated for n1 and n2
	free(n1);
	
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