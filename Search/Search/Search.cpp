#include "BinarySearchTree.h"

void PrintSearchResult(int SearchTarget, BSTNode* Result)
{
	if (Result != nullptr)
		std::cout << "Found: " << Result->Data;
	else
		std::cout <<"notFound: " << SearchTarget;
}
int main()
{
	BSTNode* Tree = BST_CreatNode(123);
	BSTNode* Node = nullptr;

	BST_InsertNode(Tree, BST_CreatNode(22));
	BST_InsertNode(Tree, BST_CreatNode(9918));
	BST_InsertNode(Tree, BST_CreatNode(424));
	BST_InsertNode(Tree, BST_CreatNode(17));
	BST_InsertNode(Tree, BST_CreatNode(3));
	BST_InsertNode(Tree, BST_CreatNode(98));
	BST_InsertNode(Tree, BST_CreatNode(34));
	BST_InsertNode(Tree, BST_CreatNode(760));
	BST_InsertNode(Tree, BST_CreatNode(317));
	BST_InsertNode(Tree, BST_CreatNode(1));

	int SearchTager = 17;
	Node = BST_SearchNode(Tree, SearchTager);
	PrintSearchResult(SearchTager, Node);

	SearchTager = 117;
	Node = BST_SearchNode(Tree, SearchTager);
	PrintSearchResult(SearchTager, Node);

	BST_inorderPrintTree(Tree);
	printf("\n");
	printf("Removing 98..\n");

	Node = BST_RemoveNode(Tree, nullptr, 98);
	BST_DestoryNode(Node);

	BST_inorderPrintTree(Tree);
	printf("\n");

	printf("Inserting 111..\n");

	BST_InsertNode(Tree, BST_CreatNode(111));
	BST_inorderPrintTree(Tree);


	BST_DestroyTree(Tree);

	return 0;

}