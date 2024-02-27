#pragma once
#include <iostream>
typedef char ElemetType;

typedef struct tagLCRSNode
{
	struct tagLCRSNode* LeftChild;
	struct tagLCRSNode* RightSibling;

	ElemetType Data;
}LCRSNode;

LCRSNode* LCRS_CreateNode(ElemetType Data);
void LCRS_DestroyNode(LCRSNode* Node);
void LCRS_DestroyTree(LCRSNode* Root);

void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child);
void LCRS_PrintTree(LCRSNode* Node, int Depth);