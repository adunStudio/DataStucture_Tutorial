#include <stdio.h>
#include "BinaryTree.h"

// 순회
// 트리를 순회하는 방법은 "루트 노드를 언제 방문하느냐"에 따라 다르다
// 전위 순회(Preorder Traversal)  C->L->R
// 중위 순회(Inorder Traversal)   L->C->R
// 후위 순회(Postorder Traversal) L->R->C

void InorderTraverse(BTreeNode* bt) // 이진 트리 전체를 중위 순회하는 함수
{
    if(bt == NULL)  // bt가 NULL이면 재귀 탈출!
    {
        return;
    }

    InorderTraverse(bt->left);  // 1단계. 왼쪽 서브 트리의 순회
    printf("%d \n", bt->data);  // 2단계. 루트 노드의 방문
    InorderTraverse(bt->right); // 3단계. 오른쪽 서브 트리의 순회
}

void PreorderTraverse(BTreeNode* bt)
{
    if(bt == NULL)  // bt가 NULL이면 재귀 탈출!
    {
        return;
    }

    printf("%d \n", bt->data);
    PreorderTraverse(bt->left);
    PreorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode* bt)
{
    if(bt == NULL)  // bt가 NULL이면 재귀 탈출!
    {
        return;
    }

    PostorderTraverse(bt->left);
    PostorderTraverse(bt->right);
    printf("%d \n", bt->data);

}

int main(void)
{
    BTreeNode* bt1 = MakeBTreeNode();
    BTreeNode* bt2 = MakeBTreeNode();
    BTreeNode* bt3 = MakeBTreeNode();
    BTreeNode* bt4 = MakeBTreeNode();

    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);

    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);


    /**
   *        1
   *     2     3
   *  4
   */


    InorderTraverse(bt1);

    return 0;
}