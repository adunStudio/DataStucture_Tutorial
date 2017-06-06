/*
 * AVL 트리는 노드가 추가될 때, 그리고 삭제될 때 트리의 균형상태를 파악해서 스스로 그 구조를 변경하여 균형을 잡는 멋진 트리이다.
 * AVL 트리에서는 균형의 정도를 표현하기 위해서 '균형 인수(Balance Factor)'라는 것을 사용한다.
 * 균형 인수 = 왼쪽 서브 트리의 높이 - 오른쪽 서브 트리의 높이
 * AVL 트리는 균형 인수의 절댓값이 2 이상인 경우에 균형을 잡기 위한 트리의 재조정('리밸런싱')을 진행한다.
 */

#include "BinaryTree2.h"

/*
 * AVL 트리
 */

typedef BTData BSTData;

// BST의 생성 및 초기화
void BSTMakeAndInit(BTreeNode** pRoot);

// 노드에 저장된 데이터 반환
BSTData BSTGetNodeData(BTreeNode* bst);

// BST를 대상으로 데이터 저장(노드의 생성과정 포함)
void BSTInsert(BTreeNode** pRoot, BSTData data);

// BST를 대상으로 데이터 탐색
BTreeNode* BSTSearch(BTreeNode* bst, BSTData target);

// 트리에서 노드를 제거하고 제거된 노드의 주소 값을 반환한다.
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target);

// 이진 탐색 트리에 저장된 모든 노드의 데이터를 출력한다.
void BSTShowALL(BTreeNode* bst);


