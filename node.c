#include "node.h"
#include <stdlib.h>
#include <stdio.h>

void print_list(struct node * front)
{
	struct node * n = front;
	printf("[ ");
	while (n != NULL) {
		if (n->next != NULL) {
			printf("%d, ", n->i);
		}
		else {
			printf("%d", n->i);
		}
		n = n->next;
	}
	printf(" ]\n");
}

struct node * insert_front(struct node * n, int i)
{
	struct node * newNode = malloc(sizeof(struct node));
	newNode->i = i;
	if (n == NULL) {
		newNode->next = NULL;
		return newNode;
	}
	newNode->next = n;
	return newNode;
}

struct node * free_list(struct node * n)
{
	if (n == NULL) return n;
	struct node * curr = n;
	struct node * after = n->next;
	printf("Freeing node: %d\n", curr->i);
	free(curr);
	while (after != NULL) {
		curr = after;
		after = curr->next;
		printf("Freeing node: %d\n", curr->i);
		free(curr);
	}
	return NULL;
}

struct node * remove_node(struct node * front, int data)
{
	struct node * n = front;
	struct node * after;
	if (n != NULL) {
		after = n->next;
		if (n->i == data) {
			free(n);
			return after;
		}
		
	}
	while (after != NULL) {
		if (after->i == data) {
			n->next = after->next;
			free(after);
			break;
		}
		n = after;
		after = n->next;
	}
	return front;
}