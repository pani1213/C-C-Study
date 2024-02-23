#pragma once
#include <iostream>
typedef int ElementType;

typedef struct tNode
{
	ElementType data;
}Node;

typedef struct tArrayStack
{
	int Top;
	int Capacity;
	Node* Nodes;

}ArrayStack;
void AS_CreateStack(tArrayStack** Stack, int Capacity);
void AS_DestroyStack(tArrayStack* Stack);
void AS_Push(tArrayStack* Stack,ElementType Data);
ElementType AS_Pop(tArrayStack* Stack);
bool AS_IsFull(tArrayStack* Stack);