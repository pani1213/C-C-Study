#include <iostream>
#include "LinkedStack.h"

void LLS_CreateStack(LinkedListStack** Stack)
{
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List = NULL;
	(*Stack)->Top  = NULL;

}

void LLS_DestroyStack(LinkedListStack* Stack)
{

	free(Stack);
}
