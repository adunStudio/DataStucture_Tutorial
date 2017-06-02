#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"


int main()
{
    BTreeNode* bstRoot;
    BTreeNode* sNode;    // search node

    BSTMakeAndInit(&bstRoot);

    BSTInsert(&bstRoot, 9);
    BSTInsert(&bstRoot, 1);
    BSTInsert(&bstRoot, 6);
    BSTInsert(&bstRoot, 2);
    BSTInsert(&bstRoot, 8);
    BSTInsert(&bstRoot, 3);
    BSTInsert(&bstRoot, 5);
    BSTInsert(&bstRoot, 1);

    BSTShowALL(bstRoot);
    printf("\n");


    sNode = BSTSearch(bstRoot, 5);

    if(sNode == NULL)
        printf("탐색 실패 \n");
    else
        printf("%d \n", BSTGetNodeData(sNode));


    sNode = BSTRemove(&bstRoot, 5);
    free(sNode);

    BSTShowALL(bstRoot);
    printf("\n");

    return 1;
}