// 배열을 기반으로 하는 테이블

#include <stdio.h>

typedef struct _empInfo
{
    int empNum;
    int age;

} EmpInfo;

int main()
{
    EmpInfo empInfoArr[10000];
    EmpInfo ei;
    int eNum;

    printf("사번과 나이 입력: ");
    scanf("%d %d", &(ei.empNum), &(ei.age));

    empInfoArr[ei.empNum] = ei;

    printf("확인하고픈 직원의 사번 입력: ");
    scanf("%d", &eNum);

    ei = empInfoArr[eNum];

    printf("사번 %d, 나이 %d, \n", ei.empNum, ei.age);

    return 1;
}