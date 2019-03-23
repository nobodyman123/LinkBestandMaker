#include "pch.h"
#include <iostream>
#include "windows.h"

//structure for node in a linked list; contains url and pointer to next node in list
typedef struct LinkedListNode {
	const char * url;
	LinkedListNode * next;
} node;

typedef struct LinkedList {
	const char* name;
	LinkedList* next_tab;
	node* next_node;
} tab;

node* create_node(const char* node_url) {
	node* n;
	n = (node*)malloc(sizeof(node));
	ZeroMemory(n, sizeof(node));
	n->url = node_url;
	return n;
}

tab* create_tab(const char* tab_name) {
	tab* t;
	t = (tab*)malloc(sizeof(tab));
	ZeroMemory(t, sizeof(tab));
	t->name = tab_name;
	return t;
}

tab* MAIN = create_tab("MAIN");

tab* get_last_tab() {
	tab* t = MAIN->next_tab;
	if (MAIN->next_tab == NULL) {
		return NULL;
	}
	while (t->next_tab != NULL) {
		t = t->next_tab;
	}
	return t;
}

void add_tab(const char* tab_name) {
	tab* last_tab = get_last_tab();
	if (last_tab == NULL) {
		MAIN->next_tab = create_tab(tab_name);
	}
	else {
		last_tab->next_tab = create_tab(tab_name);
	}
}

node* get_last_node(tab* tab) {
	node* n = tab->next_node;
	if (n == NULL) { 
		return NULL; 
	}
	while (n->next != NULL) {
		n = n->next;
	}
	return n;
}

void add_list_item(tab* tab, const char* node_url) {
	node* last_node = get_last_node(tab);
	if (last_node == NULL) {
		tab->next_node = create_node(node_url);
	}
	else {
		last_node->next = create_node(node_url);	
	}
}

//prints urls of all nodes in list with first node: "first_node"
//format: node["pointer to node"]: "url"
void print_list(tab* tab) {
	node* n = tab->next_node;

	printf("%s\n", tab->name);
	if (n != NULL) {
		while (n->next != NULL) {
			printf("node[%p]: %s\n", n, n->url);
			n = n->next;
		}
		printf("node[%p]: %s\n", n, n->url);
	}
	printf("END\n\n");
}



int main() {
	add_tab("LIST 1");
	add_list_item(MAIN->next_tab, "https://google.com");
	add_list_item(MAIN->next_tab, "hi!");
	print_list(MAIN->next_tab);
	printf("%p: %s -> %p: %s", MAIN, MAIN->name, MAIN->next_tab, MAIN->next_tab->name);

	return 0;
}