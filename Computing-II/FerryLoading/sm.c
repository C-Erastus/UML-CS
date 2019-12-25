#include <stdio.h>
#include <stdlib.h>

const int METERS_TO_CM = 100;


enum status { FAILURE, SUCCESS };
typedef enum status Status;

enum boolean { FALSE, TRUE };
typedef enum boolean Boolean;


typedef void* QUEUE;

QUEUE queue_init_default(void);

Status queue_enqueue(QUEUE hQueue, int item);
Status queue_service(QUEUE hQueue);
int queue_front(QUEUE hQueue, Status* pStatus);
Boolean queue_empty(QUEUE hQueue);

void queue_destroy(QUEUE* phQueue);


struct node;
typedef struct node Node;

typedef struct node
{
  int size;
  Node* next;
  Node* previous;
}Node;

typedef struct queue
{
  Node* pHead;
  Node* pTail;
}Queue;

typedef struct queue Queue;

int ferry_boat_trial(void);
void buffclear(void);

int main(int argc, char* argv[])
{
  int number_of_trials = 0;
  int i = 0;

  scanf(" %d", &number_of_trials);
  buffclear();

  for (i = 0; i < number_of_trials; i++)
  {
    printf("%d\n", ferry_boat_trial());
  }
  return 0;
}

int ferry_boat_trial(void)
{ 
  QUEUE* hQueue_Left;
  QUEUE* hQueue_Right;

  int length;
  int length_count;
  int number_of_cars;
  int crosses = 0;
  int i = 0;
  int car_length = 0;
  char car_side;

  hQueue_Left = queue_init_default();
  hQueue_Right = queue_init_default();

  scanf(" %d%d", &length, &number_of_cars);
  buffclear();
  length_count = length;
  length = length * METERS_TO_CM;
  length_count = length_count * METERS_TO_CM;

  for (i = 0; i < number_of_cars; i++)
  {
    scanf(" %d %c", &car_length, &car_side);
    buffclear();
    if (car_side == 'r' || car_side == 'R')
    {
      queue_enqueue(hQueue_Right, car_length);
    }
    else if (car_side == 'l' || car_side == 'L')
    {
      queue_enqueue(hQueue_Left, car_length);
    }
  }

  while (!queue_empty(hQueue_Left) && !queue_empty(hQueue_Right))
  {
    while (queue_front(hQueue_Left, NULL) < length)
    {
      length = length - queue_front(hQueue_Left, NULL);
      queue_service(hQueue_Left);
    }

    length = length_count;
    while (queue_front(hQueue_Right, NULL) < length)
    {
      length = length - queue_front(hQueue_Right, NULL);
      queue_service(hQueue_Right);
    }

    length = length_count;
    crosses = crosses + 2;
  }
  while (!queue_empty(hQueue_Left))
  {
    while (queue_front(hQueue_Left, NULL) < length)
    {
      length = length - queue_front(hQueue_Left, NULL);
      queue_service(hQueue_Left);
    }
    crosses++;
    if (!queue_empty(hQueue_Left))
    {
      crosses++;
    }
    length = length_count;
  }
  while (!queue_empty(hQueue_Right))
  {
    while (queue_front(hQueue_Right, NULL) < length)
    {
      length = length - queue_front(hQueue_Right, NULL);
      queue_service(hQueue_Right);
    }
    crosses++;
    crosses++;
    length = length_count;
  }
  queue_destroy(&hQueue_Left);
  queue_destroy(&hQueue_Right);
  return crosses;
}

void buffclear(void)
{
  char z;
  scanf("%c", &z);
  while (z != '\n')
  {
    scanf("%c", &z);
  }
  return;
}





QUEUE queue_init_default(void)
{
  Queue* pQueue;

  pQueue = (Queue*)malloc(sizeof(Queue));
  if (pQueue != NULL)
  {
    pQueue->pHead = NULL;
    pQueue->pTail = NULL;
  }
  return pQueue;
}

Status queue_enqueue(QUEUE hQueue, int size)
{
  Queue* pQueue = (Queue*)hQueue;
  Node* temp;
  temp = (Node*)malloc(sizeof(Node));
  if (temp == NULL)
    return FAILURE;

  temp->size = size;
  temp->next = NULL;
  if(pQueue != NULL){
    if (pQueue->pTail != NULL) {
      pQueue->pTail->next = temp;
    }
    temp->previous = pQueue->pTail;
    pQueue->pTail = temp;
    if (pQueue->pHead == NULL)
      pQueue->pHead = temp;
  }
  return SUCCESS;
}

Status queue_service(QUEUE hQueue)
{
  Queue* pQueue = (Queue*)hQueue;
  Node* temp;

  if (queue_empty(hQueue)) {
    return FAILURE;
  }
  if (pQueue->pHead->next == NULL) {
    free(pQueue->pHead);
    pQueue->pHead = NULL;
    return SUCCESS;
  }
  temp = pQueue->pHead->next;
  free(pQueue->pHead);
  pQueue->pHead = temp;

  return SUCCESS;
} 

int queue_front(QUEUE hQueue, Status* pStatus)
{
  Queue* pQueue = (Queue*)hQueue;
  if (queue_empty(hQueue)) {
    if (pStatus != NULL)
    {
      *pStatus = FAILURE;
    }
    return -8887888;
  }
  if (pStatus != NULL)
  {
    *pStatus = SUCCESS;
  }
  return pQueue->pHead->size;
}

Boolean queue_empty(QUEUE hQueue)
{
  Queue* pQueue = (Queue*)hQueue;

  return (Boolean)(pQueue->pHead == NULL);
}

void queue_destroy(QUEUE* phQueue)
{
  Queue* pQueue = (Queue*)*phQueue;
  Node* temp;

  while (pQueue->pHead != NULL) 
  {
    temp = pQueue->pHead;
    pQueue->pHead = pQueue->pHead->next;
    free(temp);
  }
  free(pQueue->pHead);
  pQueue->pHead = NULL;
  *phQueue = NULL;
  return;
}




