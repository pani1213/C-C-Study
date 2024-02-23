#include"Stack.h"

void AS_CreateStack(tArrayStack** Stack, int Capacity)
{
	(*Stack) = (tArrayStack*)malloc(sizeof(tArrayStack));
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = -1;
}
	
void AS_DestroyStack(tArrayStack* Stack)
{
	free(Stack->Nodes);
	free(Stack);
}

void AS_Push(tArrayStack* Stack, ElementType Data)
{
	Stack->Top++;
	Stack->Nodes[Stack->Top].data = Data;
}

ElementType AS_Pop(tArrayStack* Stack)
{
	int Position = Stack->Top--;
	return Stack->Nodes[Position].data;
}

bool AS_IsFull(tArrayStack* Stack)
{
	if (Stack->Top == Stack->Capacity - 1)
		return true;
	else
		return false;
}
