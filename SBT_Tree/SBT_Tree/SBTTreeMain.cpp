#include "SBTTree.h"

int main()
{
	SBTNode* A = SBT_CreateNode('A');
	SBTNode* B = SBT_CreateNode('B');
	SBTNode* C = SBT_CreateNode('C');
	SBTNode* D = SBT_CreateNode('D');
	SBTNode* E = SBT_CreateNode('E');
	SBTNode* F = SBT_CreateNode('F');
	SBTNode* G = SBT_CreateNode('G');
	SBTNode* H = SBT_CreateNode('H');
	SBTNode* I = SBT_CreateNode('I');
	SBTNode* J = SBT_CreateNode('J');

	A->Left = B;
	B->Left = C;
	B->Right = D;
	A->Right = E;
	E->Left = F;
	E->Right = G;

	C->Left = H;
	C->Right = I;
	H->Left = J;

	SBT_PreorderPrintTree(A);

	SBT_DestroyTree(A);
	return 0;
}