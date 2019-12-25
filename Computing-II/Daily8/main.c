#include <stdio.h>
#include "priority_queue.h"

int main(int argc, char* argv[])
{
	int i;

	PRIORITY_QUEUE hQueue = priority_queue_init_default();

	for(i = 0; i < 100; i++)
	{
		priority_queue_insert(hQueue, i, i);
	}

	while(!priority_queue_is_empty(hQueue))
	{
		printf("%d\n", priority_queue_front(hQueue, NULL));
		priority_queue_service(hQueue);
	}

	priority_queue_destroy(&hQueue);

	return 0;
}
