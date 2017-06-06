#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree2.h"

BTreeNode* MakeBTreeNode(void)
{
    BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));
    nd->left  = NULL;
    nd->right = NULL;

    return nd;
}

BTData GetData(BTreeNode* bt)
{
    return bt->data;
}

void SetData(BTreeNode* bt, BTData data)
{
    bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
    return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt)
{
    return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
    if(main->left != NULL)
    {
        free(main->left);
    }

    main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
    if(main->right != NULL)
    {
        free(main->right);
    }

    main->right = sub;
}

// 순회
// 트리를 순회하는 방법은 "루트 노드를 언제 방문하느냐"에 따라 다르다
// 전위 순회(Preorder Traversal)  C->L->R
// 중위 순회(Inorder Traversal)   L->C->R
// 후위 순회(Postorder Traversal) L->R->C

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action) // 이진 트리 전체를 중위 순회하는 함수
{
    if(bt == NULL)  // bt가 NULL이면 재귀 탈출!
        return;


    InorderTraverse(bt->left, action);  // 1단계. 왼쪽 서브 트리의 순회
    action(bt->data);  // 2단계. 루트 노드의 방문
    InorderTraverse(bt->right, action); // 3단계. 오른쪽 서브 트리의 순회
}

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
    if(bt == NULL)  // bt가 NULL이면 재귀 탈출!
       return;


    action(bt->data);
    PreorderTraverse(bt->left, action);
    PreorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
    if(bt == NULL)  // bt가 NULL이면 재귀 탈출!
    {
        return;
    }

    PostorderTraverse(bt->left, action);
    PostorderTraverse(bt->right, action);
    action(bt->data);
}

// 왼쪽 자식노드를 트리에서 제거, 제거된 노드의 주소 값이 반환된다.
BTreeNode* RemoveLeftSubTree(BTreeNode* bt)
{
    BTreeNode* delNode;

    if(bt != NULL)
    {
        delNode = bt->left;
        bt->left = NULL;
    }

    return delNode;
}

// 오른쪽 자식노드를 트리에서 제거, 제거된 노드의 주소 값이 반환된다.
BTreeNode* RemoveRightSubTree(BTreeNode* bt)
{
    BTreeNode* delNode;

    if(bt != NULL)
    {
        delNode = bt->right;
        bt->right = NULL;
    }

    return delNode;
}

// 메모리 소멸을 수반하지 않고 main의 왼쪽 자식 노드를 변경한다.
void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
    main->left = sub;
}

// 메모리 소멸을 수반하지 않고 main의 오른쪽 자식 노드를 변경한다.
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
    main->right = sub;
}