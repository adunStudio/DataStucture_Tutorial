#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

int getOpPrec(char op);
void convToRPNExp(char exp[]);

int main()
{

    // 중위표기식 -> 후위표기식
    // 5+2/7   -> 527/+
    // 1. 피연산자는 그냥 옮긴다.
    // 2. 연산자는 쟁반으로 옮긴다.
    // 3. 연산자가 쟁반에 있다면 우선순위를 비교하여 처리한다.
    // 4. 마지막까지 쟁반에 남아있는 연산자들은 하나씩 꺼내서 옮긴다
    // 후위표기법의 수식에서는 먼저 연산이 이뤄줘야하는 연산자가 뒤에 연산이 이뤄지는 연산자보다 앞에 위치해야한다

    char exp[] = "3-2+4";
    return 0;
}

int getOpPrec(char op)    // 연산자의 연산 우선순위 정보를 반환한다.
{
    switch(op)
    {
        case '*':
        case '/':
            return 5;    // 가장 높은 연산의 우선순위
        case '+':
        case '-':
            return 3;    // 5보다 작고 1보다 높은 연산의 우선순위
        case '(':        // 가장 낮은 연산의 우선순위  )연산자가 등장할 때까지 쟁반에 남아서 소괄호의 경계를 구분하는 도구로 사용
            return 1;
    }

    return -1;           // 등록되지 않은 연산자임을 알림
}

void convToRNPExp(char exp[])
{
    Stack stack;
    int expLen = strlen(exp);
    char* convExp = (char*)malloc(expLen+1);        // 변환된 수식을 담을 공간

    int i, idx = 0;
    char tok, popOp;

    memset(convExp, 0, sizeof(char) * expLen + 1);  // 할당된 배열을 0으로 초기화

    StackInit(&stack);

    for(i = 0; i < expLen; ++i)
    {
        tok = exp[i];              // exp로 전달된 수식을 한 문자씩 tok에 저장

        if(isdigit(tok))
        {

        }
    }
}

