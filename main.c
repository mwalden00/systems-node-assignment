#include "node.h"
#include <stdlib.h>
#include <stdio.h>

int main() 
{
	int i;
	struct node * n = NULL;

	printf("Printing empty list:\n");
	print_list(n);

	printf("Adding #s 0-9 to list.\n");
	for (i = 0; i < 10; i++) {
		n = insert_front(n, i);
	}

	printf("Printing list:\n");
	print_list(n);

	printf("Removing 9:\n");
	n = remove_node(n,9);
	print_list(n);

	printf("Removing 4:\n");
	n = remove_node(n,4);
	print_list(n);

	printf("Removing 0:\n");
	n = remove_node(n,0);
	print_list(n);

	printf("Removing -1:\n");
	n = remove_node(n,-1);
	print_list(n);

	printf("Freeing list.\n");
	n = free_list(n);

	printf("Printing list:\n");
	print_list(n);

	return 0;
}