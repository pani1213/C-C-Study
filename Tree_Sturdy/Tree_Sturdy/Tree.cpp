#include "Tree.h"

// 1. 자유 저장소에 메모리를 할당하고 
// 2. 데이터를 저장한다
LCRSNode* LCRS_CreateNode(ElemetType Data)
{
	LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;
	NewNode->Data = Data;
	return NewNode;
}

void LCRS_DestroyNode(LCRSNode* Node)
{
	free(Node);
}

void LCRS_DestroyTree(LCRSNode* Root)
{
	if (Root->LeftChild != nullptr)
		LCRS_DestroyTree(Root->LeftChild);
	if(Root->RightSibling != nullptr)
		LCRS_DestroyTree(Root->RightSibling);

	Root->LeftChild = nullptr;
	Root->RightSibling = nullptr;

	free(Root);
}

void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child)
{
	if (Parent->LeftChild == NULL)
		Parent->LeftChild = Child;
	else
	{
		LCRSNode* TempNode = Parent->LeftChild;
		while (TempNode->RightSibling != NULL)
			TempNode = TempNode->RightSibling;

		TempNode->RightSibling = Child;
	}
}

void LCRS_PrintTree(LCRSNode* Node, int Depth)
{
	int i = 0;
	for (i = 0; i < Depth - 1; i++)
		printf("   ");

	if(Depth >0)
		printf("+--");

	printf("%c\n", Node->Data);

	if (Node->LeftChild != NULL)
		LCRS_PrintTree(Node->LeftChild, Depth + 1);

	if(Node->RightSibling != NULL)
		LCRS_PrintTree(Node->RightSibling, Depth);

}

