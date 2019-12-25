#ifndef QUEUE_H
#define QUEUE_H

#include "status.h"

typedef void* QUEUE;

QUEUE queue_init_default(void);

// insert in the queue
Status queue_insert(QUEUE hQueue, int item);

//serviice the queue
Status queue_service(QUEUE hQueue);

int queue_front(QUEUE hQueue, Status* pStatus);
//queue empty
Boolean queue_empty(QUEUE hQueue);
//destroy
void queue_destroy(QUEUE* phQueue);

#endif
