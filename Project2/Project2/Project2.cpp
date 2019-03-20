// Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "windows.h"

//structure for node in a linked list; contains url and pointer to next node in list
typedef struct LinkedListNode {
	const char * url;
	LinkedListNode * next;
} node;

//creates node with url: "node_url"
node* create_node(const char* node_url) {
	node* n;
	n = (node*)malloc(sizeof(node));
	ZeroMemory(n, sizeof(node));
	n->url = node_url;
	return n;
}

//returns last node of list with first node: "first_node"
node* get_last_node(node* first_node) {
	if (first_node->next != NULL) {
		get_last_node(first_node->next);
	}
	else if (first_node->next == NULL) {
		return first_node;
	}
}

//adds item to list with first node: "firs_node"; new node will have url: "node_url"
node* add_list_item(node* first_node, const char* node_url) {
	node* last_node = get_last_node(first_node);
	last_node->next = create_node(node_url);
	return last_node->next;
}

//deletes item with url: "node_url" in list with first node: "first_node"
void delete_list_item(node* first_node, const char* node_url) {
	const char* next_url = first_node->next->url;
	node* next_next = first_node->next->next;
	if (first_node->next == NULL) {
		printf("ERROR: node not found");
		//prints error message if node with url:"node_url" is not found in list
	}
	else if (next_url != node_url) {
		delete_list_item(first_node->next, node_url);
		//re-iterates
	}
	else if (next_url == node_url) {
		free(first_node->next);
		first_node->next = next_next;
		//deletes desired node
	}
}

//prints urls of all nodes in list with first node: "first_node"
//format: node["pointer to node"]: "url"
void print_list(node* first_node) {
	if (first_node->next != NULL) {
		printf("node [%p]: %s\n", first_node, first_node->url);
		print_list(first_node->next);
	}
	else if(first_node->next == NULL) {
		printf("node [%p]: %s\n", first_node, first_node->url);
		printf("END\n");
	}
}

int main() {
	//TEST CODE

	//create first node in list with url: NULL
	node* first = create_node(NULL);

	//add nodes to list
	add_list_item(first, "https://devdocs.io/c/");
	add_list_item(first, "https://en.wikibooks.org/wiki/C_Programming/Simple_input_and_output");

	//print list
	print_list(first);
	printf("\n");

	//delete item from list
	delete_list_item(first, "https://devdocs.io/c/");

	//print new list
	print_list(first);
	
	return 0;
}