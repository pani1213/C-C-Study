#include <iostream>
#include "LinkedStack.h"
int main()
{
	int i = 0;
	int Count = 0;
	Node* Popped;

	LinkedListStack* Stack;

	LLS_CreateStack(&Stack);

	LLS_Push(Stack, LLS_CreateNode("abs"));
	LLS_Push(Stack, LLS_CreateNode("def"));
	LLS_Push(Stack, LLS_CreateNode("efg"));
	LLS_Push(Stack, LLS_CreateNode("hij"));

	Count = LLS_GetSize(Stack);

	std::cout << "Size: " << Count << "   Top:  " << LLS_Top(Stack)->Data << "\n";

	for (i = 0; i < Count; i++)
	{
		if (LLS_IsEmpty(Stack))
			break;
		Popped = LLS_Pop(Stack);

		std::cout << "Poppend: " << Popped->Data << "\n";

		LLS_DestroyNode(Popped);
		if (!LLS_IsEmpty(Stack))
		{
			std::cout << "  Current Top:  " << LLS_Top(Stack)->Data << "\n";
		}
		else
			std::cout << "stack is empty" << "\n";
	}
	LLS_DestroyStack(Stack);

	return 0;

}