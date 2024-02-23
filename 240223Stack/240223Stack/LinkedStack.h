#pragma once

typedef struct tagNode
{
	char* Data;
	struct tagNode* NextNode;
}Node;
typedef struct tagLinkedListStack
{
	Node* List;
	Node* Top;
}LinkedListStack;

void LLS_CreateStack(LinkedListStack** Stack);
void LLS_DestroyStack(LinkedListStack* Stack);
