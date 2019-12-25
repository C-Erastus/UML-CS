#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct node;

typedef struct node Node;

struct node
{
	char data;
	Node* next;
};

//known type
struct stack
{
	Node* head;
};

typedef struct stack Stack;


//init
STACK stack_init_default(void)
{
	Stack* pStack = NULL;
	pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack != NULL)
	{
		pStack->head = NULL;
	}
	return (STACK)pStack;
}

//push
Status stack_push(STACK hStack, char item)
{
	Stack* pStack = (Stack*)hStack;
	Node* temp;

	temp = (Node*)malloc(sizeof(Node));
	if (temp == NULL)
	{
		return FAILURE;
	}
	temp->data = item;
	temp->next = pStack->head;
	pStack->head = temp;

	return SUCCESS;
}

//pop
Status stack_pop(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;
	Node* temp;

	if (pStack->head == NULL)//stack is empty
	{
		return FAILURE;
	}
	temp = pStack->head;
	pStack->head = pStack->head->next;
	free(temp);
	return SUCCESS;
}

//top
//Status stack_top(STACK hStack, int* pValue_of_top);
int stack_top(STACK hStack, Status* pStatus)
{
	//printf("Checking stack top\n");
	Stack* pStack = (Stack*)hStack;

	if (pStack->head == NULL)//empty
	{
		if (pStatus != NULL)
		{
			*pStatus = FAILURE;
		}
		return -1337;
	}
  if(pStatus != NULL)
  {
		*pStatus = SUCCESS;
  }
	return pStack->head->data;
}

//empty
Boolean stack_empty(STACK hStack)
{
	Stack* pStack = (Stack*)hStack;

	return (Boolean)(pStack->head == NULL);
}

//destroy
void stack_destroy(STACK* phStack)
{
	Stack* pStack = (Stack*)*phStack;
	Node* temp;
	temp = pStack->head;
	while (temp != NULL)
	{
		pStack->head = pStack->head->next;
		free(temp);
		temp = pStack->head;
	}

	free(pStack);
	*phStack = NULL;

	return;
}
