#include "BinaryTree2.h"

// RR회전을 담당하는 함수
BTreeNode* RotateRR(BTreeNode* bst);

// LL회전을 담당하는 함수
BTreeNode* RotateLL(BTreeNode* bst);

BTreeNode* RotateLR(BTreeNode* bst);

BTreeNode* RotateRL(BTreeNode* bst);

// 트리의 높이를 계산하여 반환
int GetHeight(BTreeNode* bst);

// 두 서브 트리의 '높이의 차(균형 인수)'를 반환
int GetHeightDiff(BTreeNode* bst);

// 트리의 균형을 잡는다.
BTreeNode* Rebalance(BTreeNode** pRoot);
