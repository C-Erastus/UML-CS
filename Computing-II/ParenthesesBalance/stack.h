#include "status.h"
typedef void* STACK;

//init
STACK stack_init_default(void);

//push
Status stack_push(STACK hStack, char item);

//pop
Status stack_pop(STACK hStack);

//top
//Status stack_top(STACK hStack, int* pValue_of_top);
int stack_top(STACK hStack, Status* pStatus);

//empty
Boolean stack_empty(STACK hStack);

//destroy
void stack_destroy(STACK* phStack);