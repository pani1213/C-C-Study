#include "BinarySearchTree.h"


BSTNode* BST_CreatNode(ElementType NewData)
{
	BSTNode* NewNode = (BSTNode*)malloc(sizeof(BSTNode));
	NewNode->Left = nullptr;
	NewNode->Right = nullptr;
	NewNode->Data = NewData;
	return NewNode;
}

void BST_DestoryNode(BSTNode* Node)
{
	free(Node);
}

void BST_DestroyTree(BSTNode* Tree)
{
	if (Tree->Right != nullptr)
		BST_DestroyTree(Tree->Right);
	if (Tree->Left != nullptr)
		BST_DestroyTree(Tree->Left);

	Tree->Left = nullptr;
	Tree->Right= nullptr;

	BST_DestoryNode(Tree);
}

void BST_InsertNode(BSTNode* Tree, BSTNode* Child)
{
	if (Tree->Data < Child->Data)
	{
		if (Tree->Right == NULL)
			Tree->Right = Child;
		else
			BST_InsertNode(Tree->Right, Child);

	}
	else if (Tree->Data > Child->Data)
	{
		if (Tree->Left == NULL)
			Tree->Left = Child;
		else
			BST_InsertNode(Tree->Left, Child);
	}

}
BSTNode* BST_SearchNode(BSTNode* Tree, ElementType Target)
{
	if (Tree == nullptr)
		return nullptr;
	if (Tree->Data == Target)
		return Tree;
	else if (Tree->Data > Target)
		return BST_SearchNode(Tree->Left, Target);
	else
		return BST_SearchNode(Tree->Right, Target);
}
BSTNode* BST_SearchMinNode(BSTNode* Tree)
{
	if (Tree == nullptr)
		return nullptr;
	if (Tree->Left == nullptr)
		return Tree;
	else
		return BST_SearchMinNode(Tree->Left);
}
BSTNode* BST_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target)
{
	BSTNode* Removed = nullptr;

	if (Tree == nullptr)
		return nullptr;

	if (Tree->Data > Target)
		Removed = BST_RemoveNode(Tree->Left, Tree, Target);
	else if (Tree->Data < Target)
		Removed = BST_RemoveNode(Tree->Right, Tree, Target);
	else
	{
		Removed = Tree;
		// 잎 노드인 경우
		if (Tree->Left == nullptr && Tree->Right == nullptr)
		{
			if (Parent->Left == Tree)
				Parent->Left = nullptr;
			else
				Parent->Right = nullptr;
		}
		else
		{
			// 자식이 양쪽 다 있을 경우
			if (Tree->Left != nullptr && Tree->Right != nullptr)
			{
				BSTNode* minNode = BST_SearchMinNode(Tree->Right);
				minNode = BST_RemoveNode(Tree, nullptr, minNode->Data);
				Tree->Data = minNode->Data;
			}
			else
			{
				BSTNode* Temp = nullptr;
				if (Tree->Left != nullptr)
					Temp = Tree->Left;
				else
					Temp = Tree->Right;

				if (Parent->Left == Tree)
					Parent->Left = Temp;
				else
					Parent->Right = Temp;
			}
		}
	}
	return Removed;
}

void BST_inorderPrintTree(BSTNode* Node)
{
	if (Node == nullptr)
		return;

	BST_inorderPrintTree(Node->Left);
	std::cout<< " " << Node->Data;
	BST_inorderPrintTree(Node->Right);
}
