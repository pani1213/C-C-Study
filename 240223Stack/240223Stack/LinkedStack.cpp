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
Node* LLS_CreateNode(const char* Data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(sizeof(Data)+1);

	strcpy_s(NewNode->Data,sizeof(NewNode->Data), Data);

	NewNode->NextNode = NULL;

	return NewNode;
}
void LLS_DestroyNode(Node* _Node)
{
	free(_Node->Data);
	free(_Node);
}

void LLS_Push(LinkedListStack* Stack, Node* NewNode)
{
	if (Stack->List == nullptr)
	{
		Stack->List = NewNode;
	}
	else
	{
		Stack->Top->NextNode = NewNode;
	}
	Stack->Top = NewNode;
}
Node* LLS_Pop(LinkedListStack* Stack)
{
	Node* NewNode = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = nullptr;
		Stack->Top = nullptr;
	}
	else
	{
		Node* CurrentTop = Stack->List;
		while (CurrentTop != NULL && CurrentTop->NextNode != Stack->Top)
		{
			CurrentTop = CurrentTop->NextNode;
		}
		Stack->Top = CurrentTop;
		Stack->Top->NextNode = nullptr;
	}
	return NewNode;
}

Node* LLS_Top(LinkedListStack* Stack)
{
	return Stack->Top;
}

int LLS_GetSize(LinkedListStack* Stack)
{
	int Count = 0;
	Node* Current = Stack->List;

	while (Current != nullptr)
	{
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
	return (Stack->List == nullptr);
}
