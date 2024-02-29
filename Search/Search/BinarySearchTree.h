#pragma once
#include <iostream>
typedef int ElementType;

typedef struct tagBSTNode
{
	ElementType Data;

	struct tagBSTNode* Left;
	struct tagBSTNode* Right;
}BSTNode;

//积己(飘府=Data)
BSTNode* BST_CreatNode(ElementType NewData);
//畴靛昏力
void BST_DestoryNode(BSTNode* Node);
//飘府昏力
void BST_DestroyTree(BSTNode* Tree);

BSTNode* BST_SearchNode(BSTNode* Tree, ElementType Target);
BSTNode* BST_SearchMinNode(BSTNode* Tree);
void BST_InsertNode(BSTNode* Tree, BSTNode* Child);
BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target);
void BST_inorderPrintTree(BSTNode* Node);
