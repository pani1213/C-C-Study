#pragma once
#include <iostream>

#include "cstdio";
#include "cstdlib";
#include "cstring";

typedef char ElementType;

typedef struct tagETNode
{
	struct tagETNode* Left;
	struct tagETNode* Right;

	ElementType Data;
}ETNode;


ETNode* ET_CreateNode(ElementType NewData);
void ET_DestroyNode(ETNode* Node);
void ET_DestroyTree(ETNode* Root);

void ET_PreorderPrintTree(ETNode* Node);
void ET_InorderPrintTree(ETNode* Node);
void ET_PostorderPrintTree(ETNode* Node);
void ET_BuildExpressionTree(char* PostfixExpression, ETNode** Node);
double ET_Evaluate(ETNode* Tree);