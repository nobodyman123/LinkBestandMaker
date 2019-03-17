// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "windows.h"

typedef struct LinkedListNode {
	const char * url;
	LinkedListNode * next;
} node;

node* create_node(const char* url) {
	node* n;
	n = (node*)malloc(sizeof(node));
	ZeroMemory(n, sizeof(node));
	n->url = url;
	return n;
	
}

int main() {
	
	node* n1 = create_node("https://www.google.com");
	node* n2 = create_node("https://devdocs.io/c/language/scope");
	n1->next = n2;
	
	printf("The URL of node 1 = %s\n", n1->url);
	printf("The URL of node 2 = %s\n", n2->url);
	printf("And the next node in the list is %p\n", n1->next);
	printf("Would you look at that, the pointer for node 2 is also %p\n", n2);
	printf("The next node after node 2 is %p\n", n2->next);

	free(n1);
	free(n2);
	
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
