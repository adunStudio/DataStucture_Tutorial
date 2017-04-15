#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "BinaryTree.h"

BTreeNode* makeExpTree(char exp[])
{
    Stack stack;
    BTreeNode* pnode;

    int expLen = strlen(exp);
    int i;

    StackInit(&stack);

    for(i = 0; i < expLen; ++i)
    {
        pnode = makeBTreeNode();

        // 연산 순서대로 왼쪽에서 오른쪽으로 연산자가 나열된다.
        // 해당 연산자의 두 피여난자는 연산자 앞에 나열된다.


        if(isdigit(exp[i]))    // 피연산자라면...
        {
            SetData(pnode, exp[i] - '0');   // 문자를 정수로 바꿔서 저장
        }
        else                   //  연산자라면...
        {
            MakeRightSubTree(pnode, SPop(&stack));
            MakeLeftSubTree(pnode, SPop(&stack));
            SetData(pnode, exp[i]);
        }

        SPush(&stack, pnode);
    }

    return SPop(&stack);
}

void ShowNodeData(int data)
{
    if(0 <= data && data <= 9)
    {
        printf("%d", data);    // 피연산자 출력
    }
    else
    {
        printf("%c", data);    //  연산자 출력
    }
}

void ShowPrefixTypeExp(BTreeNode* bt)
{
    PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode* bt)
{
    InorderTraverse(bt, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode* bt)
{
    PostorderTraverse(bt, ShowNodeData);
}