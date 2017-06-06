#include "BinaryTree2.h"

// RR회전을 담당하는 함수
BTreeNode* RotateRR(BTreeNode* bst)
{
    BTreeNode* pNode;    // parent node
    BTreeNode* cNode;    //  child node

    // pNode와 cNode가 RR회전을 위해 적절한 위치를 가리키게 한다.
    pNode = bst;
    cNode = GetRightSubTree(pNode);

    // 실제 RR회전을 담당하는 두 개의 문장
    ChangeRightSubTree(pNode, GetLeftSubTree(cNode));
    ChangeLeftSubTree(cNode, pNode);

    // RR회전으로 인해서 변경된 루트 노드의 주소 값 반환
    return cNode;
}

// LL회전을 담당하는 함수
BTreeNode* RotateLL(BTreeNode* bst)
{
    BTreeNode* pNode;    // parent node
    BTreeNode* cNode;    //  child node

    // pNode와 cNode가 LL회전을 위해 적절한 위치를 가리키게 한다.
    pNode = bst;
    cNode = GetLeftSubTree(pNode);

    // 실제 LL회전을 담당하는 두 개의 문장
    ChangeLeftSubTree(pNode, GetRightSubTree(cNode));
    ChangeRightSubTree(cNode, pNode);

    // LL회전으로 인해서 변경된 루트 노드의 주소 값 반환
    return cNode;
}

BTreeNode* RotateLR(BTreeNode* bst)
{
    BTreeNode* pNode;    // parent node
    BTreeNode* cNode;    //  child node

    // pNode와 cNode가 LR회전을 위해 적절한 위치를 가리키게 한다
    pNode = bst;
    cNode = GetRightSubTree(pNode);

    // 실제 LR회전을 담당하는 두 개의 문장
    ChangeLeftSubTree(pNode, RotateRR(cNode));    // 부분적 RR회전

    return RotateLL(pNode);
}

BTreeNode* RotateRL(BTreeNode* bst)
{
    BTreeNode* pNode;    // parent node
    BTreeNode* cNode;    //  child node

    // pNode와 cNode가 RL회전을 위해 적절한 위치를 가리키게 한다
    pNode = bst;
    cNode = GetRightSubTree(pNode);

    // 식제 RL회전을 담당하는 두 개의 문장
    ChangeRightSubTree(pNode, RotateLL(cNode));   // 부분적 LL회전

    return RotateRR(pNode);
}

// 트리의 높이를 계산하여 반환
int GetHeight(BTreeNode* bst)
{
    int  leftH;    //  left height
    int rightH;    // right height

    if(!bst)
        return 0;

    leftH  = GetHeight(GetLeftSubTree(bst));     //  왼쪽 서브 트리 높이 계산
    rightH = GetHeight(GetRightSubTree(bst));    // 오른쪽 서브 트리 높이 계산

    // 큰 값의 높이를 반환한다
    if(leftH > rightH)
        return leftH  + 1;
    else
        return rightH + 1;
}

// 두 서브 트리의 '높이의 차(균형 인수)'를 반환
int GetHeightDiff(BTreeNode* bst)
{
    int lsh;    //  left sub tree height
    int rsh;    // right sub tree height

    if(!bst)
        return 0;

    lsh = GetHeight(GetLeftSubTree(bst));    //  왼쪽 서브 트리의 높이
    rsh = GetHeight(GetRightSubTree(bst));   //  오른쪽 서브 트리의 높이

    return lsh - rsh;    // 균형 인수 계산 결과
}

// 트리의 균형을 잡는다.
BTreeNode* Rebalance(BTreeNode** pRoot)
{
    int diff = GetHeightDiff(*pRoot);

    // 균형 인수가 +2 이상이면 LL상태 또는 LR상태이다.
    if(diff > 1)    // 왼쪽 서브 트리 방향으로 높이가 2 이상 크다면,
    {
        if(GetHeightDiff(GetLeftSubTree(*pRoot)) > 0)  // LL 상태라면
            *pRoot = RotateLL(*pRoot);
        else                                           // LR 상태라면,
            *pRoot = RotateLR(*pRoot);
    }

    // 균형 인수가 -2 이하이면 RR상태 또는 RL상태이다.
    if(diff < -1)    // 오른쪽 서브 트리 방향으로 2 이상 크다면,
    {
        if(GetHeightDiff(GetRightSubTree(*pRoot)) < 0)
            *pRoot = RotateRR(*pRoot);
        else
            *pRoot = RotateRL(*pRoot);
    }

    return *pRoot;
}




