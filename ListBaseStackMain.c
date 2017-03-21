#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"


/****************************
 *
 * 스택을 이용한 계산기 예제
 *
 */

int getOpPrec(char op);
int whoPrecOp(char op1, char op2);
void convToRPNExp(char exp[]);       // 중위표기식 -> 후위표기식
int EvalRPNExp(char exp[]);          // 후위 표기법의 수식을 계산하여 그 결과를 반환

int main()
{

    // 중위표기식 -> 후위표기식
    // 5+2/7   -> 527/+
    // 1. 피연산자는 그냥 옮긴다.
    // 2. 연산자는 쟁반으로 옮긴다.
    // 3. 연산자가 쟁반에 있다면 우선순위를 비교하여 처리한다.
    // 4. 마지막까지 쟁반에 남아있는 연산자들은 하나씩 꺼내서 옮긴다
    // 후위표기법의 수식에서는 먼저 연산이 이뤄줘야하는 연산자가 뒤에 연산이 이뤄지는 연산자보다 앞에 위치해야한다

    char exp1[] = "3+2*4";
    char exp2[] = "(3+2)*4";
    char exp3[] = "((1-2)+3)*(5-2)";

    convToRPNExp(exp1);
    convToRPNExp(exp2);
    convToRPNExp(exp3);

    printf("%s: %d \n", exp1, EvalRPNExp(exp1));
    printf("%s: %d \n", exp2, EvalRPNExp(exp2));
    printf("%s: %d \n", exp3, EvalRPNExp(exp3));

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



int whoPrecOp(char op1, char op2)
{
    int op1Prec = getOpPrec(op1);
    int op2Prec = getOpPrec(op2);

    if(op1Prec > op2Prec)
    {
        return 1;
    }
    else if(op1Prec < op2Prec)
    {
        return -1;
    }

    return 0;
}



void convToRPNExp(char exp[])
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
            convExp[idx++] = tok;  // 숫자이면 배열 convExp에 그냥 저장
        }
        else
        {
            switch(tok)
            {
                case '(':                // 여는 소괄호라면,
                    SPush(&stack, tok);  // 스택에 쌓는다
                    break;

                case ')':                // 닫는 소괄호라면,
                    while(1)
                    {
                        popOp = SPop(&stack);
                        if(popOp == '(')
                        {
                            break;
                        }
                        convExp[idx++] = popOp;
                    }
                    break;

                case '+':
                case '-':
                case '*':
                case '/':
                    while(!SIsEmpty(&stack) && whoPrecOp(SPeek(&stack), tok) >= 0)  // 스택에 저장된 dus자가 먼저 연산이 되어야 하는 경우,
                    {
                        convExp[idx++] = SPop(&stack);
                    }
                    SPush(&stack, tok);
                    break;
            }
        }
    }


    while(!SIsEmpty(&stack))           // 스택에 남아 잇는 모든 연산자를,
    {
        convExp[idx++] = SPop(&stack); // 배멸 convExp로 이동
    }

    strcpy(exp, convExp);
    free(convExp);
}

int EvalRPNExp(char exp[])
{
    Stack stack;
    int expLen = strlen(exp);
    int i;
    char tok, op1, op2;

    StackInit(&stack);

    for(i = 0; i < expLen; ++i)
    {
        tok = exp[i];

        if(isdigit(tok))
        {
            SPush(&stack, tok - '0');   // 정수면 숫자로 변환 후 스택에 push
        }
        else
        {
            op2 = SPop(&stack);
            op1 = SPop(&stack);

            switch(tok)
            {
                case '+':
                    SPush(&stack, op1 + op2);
                    break;

                case '-':
                    SPush(&stack, op1 - op2);
                    break;

                case '*':
                    SPush(&stack, op1 * op2);
                    break;

                case '/':
                    SPush(&stack, op1 / op2);
                    break;
            }
        }
    }

    return SPop(&stack);
}

