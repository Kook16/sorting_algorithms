#include "sort.h"
void swap_nodes(listint_t **list, listint_t *a, listint_t *b);

/**
 * insertion_sort -  sorts a doubly linked list of integers in ascending order\
using the Insertion sort algorithm
 * @list: A pointer to a pointer to a linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *head, *current, *prevNode, *temp;

	if (*list == NULL || (*list)->next == NULL)
		return;

	head = *list;
	current = head->next;

	while (current != NULL)
	{
		temp = current->next;
		prevNode = current->prev;

		while (prevNode != NULL && prevNode->n > current->n)
		{
			prevNode->next = current->next;

			if (current->next != NULL)
				current->next->prev = prevNode;

			current->next = prevNode;
			current->prev = prevNode->prev;

			if (prevNode->prev != NULL)
				prevNode->prev->next = current;

			prevNode->prev = current;

			prevNode = current->prev;
			print_list(*list);

		}

		current = temp;
	}

	/* Update the head of the list after sorting */
	while (head->prev != NULL)
		head = head->prev;

	*list = head;
}
