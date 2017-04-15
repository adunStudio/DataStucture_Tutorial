#include <stdio.h>
#include "BinaryTree.h"

void showIntData(int data);

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




    InorderTraverse(bt1, showIntData);

    return 0;
}

void showIntData(int data)
{
    printf("%d ", data);
}