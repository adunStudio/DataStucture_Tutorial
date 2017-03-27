#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
    BTData data;
    struct _bTreeNode* left;
    struct _bTreeNode* right;

} BTreeNode;

BTreeNode* MakeBTreeNode(void);                        // 노드 생성
BTData GetData(BTreeNode* bt);                         // 노드에 저장된 데이터를 반환
void SetData(BTreeNode* bt, BTData data);              // 노드에 데이터를 저장

BTreeNode* GetLeftSubTree(BTreeNode* bt);              // 왼쪽  서브 트리 주소 값 반환
BTreeNode* GetRightSubTree(BTreeNode* bt);             // 오른쪽 서브 트리 주소 값 반환

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);  // 노드의 왼쪽 자식 노드로 연결
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub); // 노드의 오른쪽 자식 노드로 연결

typedef void VisitFuncPtr(BTData data);

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);
#endif