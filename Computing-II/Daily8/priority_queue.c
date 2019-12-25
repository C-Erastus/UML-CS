#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"

typedef struct node {
	int priority_level;
	int data;
} Node;	


typedef struct heap { 
	int size;
	int capacity;
	Node* items;
}Heap;

PRIORITY_QUEUE priority_queue_init_default(void)
{
	Heap* pHeap; // creates a pointer to a heap structure

	pHeap = (Heap*)malloc(sizeof(Heap)); // create memory for struct
	// check to see if it fails
	if(pHeap == NULL)
	{
		printf("Memory space was not allocated for heap. FAILED.");
		exit(1);
	}
	// initialize the size, cap, and struct of items
	pHeap->size = 0;
	pHeap->capacity = 1;
	pHeap->items = (Node*)malloc(sizeof(Node) * pHeap->capacity);
	//check to see if it fails
	if(pHeap->items == NULL)
	{
		printf("Memory space was not allocated for items. FAILED.");
		free(pHeap); // free memory space pointing to the heap struct
		return NULL;
	}

	return (PRIORITY_QUEUE)pHeap;
}

Status priority_queue_insert(PRIORITY_QUEUE hQueue, int priority_level, int data_item)
{
	Heap* pHeap = (Heap*)hQueue; // cast the handle to the known type
	Node* temp; // create a pointer to an node structure
	Node new_node, temp_swap;
	int i, parent_index, child_index;

	//check to see if the size is greater than the capacity
	//if yes, malloc space for it, if not just place it into the next
	//available spot in the array
	if(pHeap->size >= pHeap->capacity)
	{
		temp = (Node*)malloc(sizeof(Node) * pHeap->capacity * 2); // increase the memory by 2
		//check to see if temp failed
		if(temp == NULL)
		{
			printf("Memory allocation for temp failed");
			return FAILURE;
		}

		for(i = 0; i < pHeap->size; i++)
		{
			temp[i] = pHeap->items[i]; // copy the contents of the array in to the temp array
		}
		free(pHeap->items); // free up the memory space where pHeap was pointing to
		pHeap->items = temp; // copy the new allocated memory back to the item array
		pHeap->capacity *= 2; // actually change the capacity in the heap structure
	}
	new_node.priority_level = priority_level;
	new_node.data = data_item;

	pHeap->items[pHeap->size] = new_node;
	pHeap->size++;

	child_index = pHeap->size -1;
	parent_index = (child_index - 1) / 2;


	//while the child index is not greater than the root and the child priority level is greater than its parent priority level continue the while loop
	while(child_index > 0 && pHeap->items[child_index].priority_level > pHeap->items[parent_index].priority_level)
	{
		temp_swap = pHeap->items[child_index];
		pHeap->items[child_index] = pHeap->items[parent_index]; //swap the nodes
		pHeap->items[parent_index] = temp_swap;
		child_index = parent_index; // keep track where the child index is
		parent_index = (child_index - 1) / 2; // recalculate the parent index
	}
		
	for(i = 0; i < pHeap->size; i++)
	{
		printf("%d ", pHeap->items[i].priority_level);
	}
	printf("\n");

	return SUCCESS;
}

Status priority_queue_service(PRIORITY_QUEUE hQueue)
{
	Heap* pHeap = (Heap*)hQueue;
	Node temp;
	int left_child, right_child, current_index;

	//if the queue is empty return failure
	if(pHeap->size == 0)
	{
		return FAILURE;
	}

	//step 1 swap the root with the last element in the list
	temp = pHeap->items[pHeap->size - 1];
	pHeap->items[pHeap->size - 1] = pHeap->items[0];
	pHeap->items[0] = temp;

	pHeap->size--; // decrease the size so the array doesn't have access to the memory of the last node

	current_index = 0;
	left_child = (2 * current_index + 1);
	right_child = (2 * current_index + 2);
	//call fix down on the root
	while((left_child < pHeap->size && pHeap->items[current_index].priority_level < pHeap->items[left_child].priority_level) ||
	      (right_child < pHeap->size && pHeap->items[current_index].priority_level < pHeap->items[right_child].priority_level))
	{
		if(right_child >= pHeap->size || pHeap->items[left_child].priority_level > pHeap->items[right_child].priority_level)
		{
			temp = pHeap->items[left_child];
			pHeap->items[left_child] = pHeap->items[current_index];
			pHeap->items[current_index] = temp;

			current_index = left_child;
			left_child = (2 * current_index + 1);
			right_child = (2 * current_index + 2);
		}
		else
		{
			temp = pHeap->items[right_child];
			pHeap->items[right_child] = pHeap->items[current_index];
			pHeap->items[current_index] = temp;

			current_index = right_child;
		}

		left_child = (2 * current_index + 1);
		right_child = (2 * current_index + 2);
	}

	return SUCCESS;
}

int priority_queue_front(PRIORITY_QUEUE hQueue, Status* pStatus)
{
	Heap* pHeap = (Heap*)hQueue;

	if(pHeap->size <= 0)
	{
		if(pStatus != NULL)
		{
			*pStatus = FAILURE;
		}
		return 1331;
	}

	if(pStatus != NULL)
	{
		*pStatus = SUCCESS;
	}
	
	return pHeap->items[0].data;
}

Boolean priority_queue_is_empty(PRIORITY_QUEUE hQueue)
{
	Heap* pHeap = (Heap*)hQueue;

	if(pHeap->size <= 0)
	{
		return TRUE;
	}

	return FALSE;
}

void priority_queue_destroy(PRIORITY_QUEUE* phQueue)
{
	Heap* pHeap = (Heap*)*phQueue;

	free(pHeap->items);
	free(pHeap);
	*phQueue = NULL;
}






