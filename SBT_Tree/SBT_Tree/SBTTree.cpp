#include "SBTTree.h"

SBTNode* SBT_CreateNode(ElementType NewData)
{
	SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode));
	NewNode->Left = nullptr;
	NewNode->Right = nullptr;
	NewNode->Data = NewData;

	return NewNode;	
}

void SBT_DestroyNode(SBTNode* Node)
{
	free(Node);
}

void SBT_PreorderPrintTree(SBTNode* Node)
{
	if (Node == nullptr)
		return;

	std::cout << Node->Data << "\n";

	SBT_PreorderPrintTree(Node->Left);
	SBT_PreorderPrintTree(Node->Right);  
}

void SBT_InorderPrintTree(SBTNode* Node)
{
	if (Node == nullptr)
		return;
	SBT_InorderPrintTree(Node->Left);
	std::cout  << Node->Data << "\n";
	SBT_InorderPrintTree(Node->Right);

}

void SBT_ProstorderPrintTree(SBTNode* Node)
{
	if (Node == nullptr)
		return;
	SBT_ProstorderPrintTree(Node->Left);
	SBT_ProstorderPrintTree(Node->Right);
	std::cout << Node->Data << "\n";
}

void SBT_DestroyTree(SBTNode* Node)
{
	if (Node == nullptr)
		return;
	SBT_DestroyTree(Node->Left);
	SBT_DestroyTree(Node->Right);
	SBT_DestroyTree(Node);
}

