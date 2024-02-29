#pragma once
#include <iostream>
typedef int ElementType;

typedef struct tagBSTNode
{
	ElementType Data;

	struct tagBSTNode* Left;
	struct tagBSTNode* Right;
}BSTNode;

//����(Ʈ��=Data)
BSTNode* BST_CreatNode(ElementType NewData);
//������
void BST_DestoryNode(BSTNode* Node);
//Ʈ������
void BST_DestroyTree(BSTNode* Tree);

BSTNode* BST_SearchNode(BSTNode* Tree, ElementType Target);
BSTNode* BST_SearchMinNode(BSTNode* Tree);
void BST_InsertNode(BSTNode* Tree, BSTNode* Child);
BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target);
void BST_inorderPrintTree(BSTNode* Node);
