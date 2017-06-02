#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree2.h"
#include "BinarySearchTree.h"

void BSTMakeAndInit(BTreeNode** pRoot)
{
    *pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* bst)
{
    return GetData(bst);
}

// BST를 대상으로 데이터 저장(노드의 생성과정 포함)
void BSTInsert(BTreeNode** pRoot, BSTData data)
{
    BTreeNode* pNode = NULL;    // parent node
    BTreeNode* cNode = *pRoot;  // current node
    BTreeNode* nNode = NULL;    // new node

    // 새로운 노드가(새 데이터가 담긴 노드가) 추가될 위치를 찾는다.
    while(cNode != NULL)
    {
        if(data == GetData(cNode))
            return;    // 데이터의(키의) 중복을 허용하지 않음

        pNode = cNode;

        if(data < GetData(cNode))
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    // pNode의 자식 노드로 추가할 새 노드의 생성
    nNode = MakeBTreeNode();    // 새 노드의 생성
    SetData(nNode, data);       // 새 노드에 데이터 저장

    // pNode의 자식 노드로 새 노드를 추가
    if(pNode != NULL)   // 새 노드가 루트 노드가 아니라면,
    {
        if(data < GetData(pNode))
            MakeLeftSubTree(pNode, nNode);
        else
            MakeRightSubTree(pNode, nNode);

    }
    else                // 새 노드가 루트 노드라면,
        *pRoot = nNode;
}

BTreeNode* BSTSearch(BTreeNode* bst, BSTData target)
{
    BTreeNode* cNode = bst;    // current node
    BSTData cd;                // current data

    while(cNode != NULL)
    {
        cd = GetData(cNode);

        if(target == cd)
            return cNode;

        if(target < cd)
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);
    }

    return NULL;    // 탐색대상이 저장되어 있지 않
}

// 트리에서 노드ㅡㄹㄹ 제거하고 제거된 노드의 주소 값을 반환한다.
BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
    // 삭제 대상이 루트 노드인 경우를 별도로 고려해야 한다.
    BTreeNode* pVRoot = MakeBTreeNode();    // 가상 루트 노드
    BTreeNode* pNode  = pVRoot;             // parent node
    BTreeNode* cNode  = *pRoot;             // current node
    BTreeNode* dNode;                       // delete node

    // 루트 노드를 pVRoot가 가리키는 노드의 오른쪽 자식 노드가 되게 한다.
    ChangeRightSubTree(pVRoot, *pRoot);

    // 삭제 대상인 노드를 탐색
    while(cNode != NULL && GetData(cNode) != target)
    {
        pNode = cNode;

        if(target < GetData(cNode))
            cNode = GetLeftSubTree(cNode);
        else
            cNode = GetRightSubTree(cNode);

        if(cNode == NULL)    // 삭제 대상이 존재하지 않는다면,
            return NULL;

        dNode = cNode;       // 삭제 대상을 dNode가 가리키게 한다.
    }

    // 1. 삭제 대상이 단말 노드인 경우
    if(GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL)
    {
        if(GetLeftSubTree(pNode) == dNode)
            RemoveLeftSubTree(pNode);
        else
            RemoveRightSubTree(pNode);
    }

    // 2. 삭제 대상이 하나의 자식 노드를 갖는 경우
    else if(GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL)
    {
        BTreeNode* dcNode;    // 삭제 대상의 자식 노드 가리킴

        if(GetLeftSubTree(dNode) != NULL)
            dcNode = GetLeftSubTree(dNode);
        else
            dcNode = GetRightSubTree(dNode);

        if(GetLeftSubTree(pNode) == dNode)
            ChangeLeftSubTree(pNode, dcNode);
        else
            ChangeRightSubTree(pNode, dcNode);
    }

    // 3. 두 개의 자식 노드를 모두 갖는 경우
    else
    {
        BTreeNode* mNode = GetRightSubTree(dNode);
        BTreeNode* mpNode = dNode;    // 대체 노드의 부모 노드 가리킴
        int delData;

        // 삭제 대상의 대체 노드를 찾는다.
        while(GetLeftSubTree(mNode) != NULL)
        {
            mpNode = mNode;
            mNode  = GetLeftSubTree(mNode);
        }

        // 대체 노드에 저장된 값을 삭제할 노드에 대입한다.
        delData = GetData(dNode);       // 대입 전 데이터 백업
        SetData(dNode, GetData(mNode)); // 대입!

        // 대체 노드의 부모 노드와 자식 노드를 연결한다.
        if(GetRightSubTree(mpNode) == mNode)
            ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
        else
            ChangeRightSubTree(mpNode, GetRightSubTree(mNode));

        dNode = mNode;
        SetData(dNode, delData);    // 백업 데이터 복원
    }

    // 삭제된 노드가 루트 노드인 경우에 대한 추가적인 처리
    if(GetRightSubTree(pVRoot) != *pRoot)
        *pRoot = GetRightSubTree(pVRoot);    // 루트 노드의 변경을 반영

    free(pVRoot);    // 가상 루트 노드의 소멸

    return dNode;    // 삭제 대상의 반환
}

void ShowIntData(int data)
{
    printf("%d ", data);
}

// 이진 탐색 트리에 저장된 모든 노드의 데이터를 출력한다.
void BSTShowALL(BTreeNode* bst)
{
    InorderTraverse(bst, ShowIntData);
}
