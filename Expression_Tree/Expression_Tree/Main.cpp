#include "ExpressionTree.h"


int main()
{

	ETNode* Root = nullptr;

	char PostfixExpression[20] = "71*52-/";
	ET_BuildExpressionTree(PostfixExpression, &Root);

	ET_PreorderPrintTree(Root);
	std::cout << "\n";
	ET_InorderPrintTree(Root);
	std::cout << "\n";
	ET_PostorderPrintTree(Root);

	std::cout << "\n" << ET_Evaluate(Root)<< "\n";
	
	ET_DestroyTree(Root);
	return 0;
}