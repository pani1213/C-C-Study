#include "ExpressionTree.h"

ETNode* ET_CreateNode(ElementType NewData)
{
	ETNode* NewNode = (ETNode*)malloc(sizeof(ETNode));

	NewNode->Left = nullptr;
	NewNode->Right = nullptr;
	NewNode->Data = NewData;

	return NewNode;
}

void ET_DestroyNode(ETNode* Node)
{
	free(Node);
}

void ET_DestroyTree(ETNode* Root)
{
	if (nullptr == Root)
		return;

	ET_DestroyTree(Root->Left);
	ET_DestroyTree(Root->Right);
	ET_DestroyNode(Root);
}

void ET_PreorderPrintTree(ETNode* Node)
{
	if (nullptr == Node)
		return;

	std::cout << Node->Data << " ";

	ET_PreorderPrintTree(Node->Left);
	ET_PreorderPrintTree(Node->Right);
}

void ET_InorderPrintTree(ETNode* Node)
{
	if (nullptr == Node)
		return;
	std::cout << "(";
	ET_InorderPrintTree(Node->Left);
	std::cout << Node->Data << " ";
	ET_InorderPrintTree(Node->Right);
	std::cout << ")";

}

void ET_PostorderPrintTree(ETNode* Node)
{
	if (nullptr == Node)
		return;
	ET_PostorderPrintTree(Node->Left);
	ET_PostorderPrintTree(Node->Right);
	std::cout << Node->Data << " ";
}

void ET_BuildExpressionTree(char* PostfixExpression, ETNode** Node)
{
	int len = strlen(PostfixExpression);
	char Token = PostfixExpression[len - 1];
	PostfixExpression[len - 1] = '\0';

	switch (Token)
	{
	case'+':case'-':case'*':case'/':
		(*Node) = ET_CreateNode(Token);
		ET_BuildExpressionTree(PostfixExpression, &(*Node)->Right);
		ET_BuildExpressionTree(PostfixExpression, &(*Node)->Left);
		break;
	default:
		(*Node) = ET_CreateNode(Token);
		break;
	}
}

double ET_Evaluate(ETNode* Tree)
{
	char temp[2];
	double Left = 0;
	double Right = 0;
	double Result = 0;

	if (Tree == NULL)
		return 0;

	switch (Tree->Data)
	{
	case'+':case'-':case'*':case'/':
		Left = ET_Evaluate(Tree->Left);
		Right = ET_Evaluate(Tree->Right);

		if (Tree->Data == '+') Result = Left + Right;
		else if (Tree->Data == '-')Result = Left - Right;
		else if (Tree->Data == '*')Result = Left * Right;
		else if (Tree->Data == '/')Result = Left / Right;
		break;
	default:
		memset(temp, 0, sizeof(temp));
		temp[0] = Tree->Data;
		Result = atof(temp);
		break;
	}

	return Result;
}
