#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraphBFS.h"
#include "DLinkedList.h"
#include "CircularQueue.h"

int WhoIsPrecede(int data1, int data2);

// 그래프의 초기화
void GraphInit(ALGraph* pg, int nv)
{
    pg->adjList = (List*)malloc(sizeof(List) * nv);
    pg->numV = nv;
    pg->numE = 0;    // 초기의 간선 수는 0개

    for(int i = 0; i < nv; ++i)
    {
        ListInit(&(pg->adjList[i]));
        SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
    }

    // 정점의 수를 길이로 하여 배열을 할당
    pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);

    // 배열의 모든 요소를 0으로 초기화!
    memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void GraphDestroy(ALGraph* pg)
{
    if(pg->adjList != NULL)
        free(pg->adjList);

    // 할달된 배열의 소멸!
    if(pg->visitInfo != NULL)
        free(pg->visitInfo);
}

// 간선의 추가
void AddEdge(ALGraph* pg, int fromV, int toV)
{
    LInsert(&(pg->adjList[fromV]), toV);
    LInsert(&(pg->adjList[toV]), fromV);

    pg->numE += 1;
}

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg)
{
    int vx;

    for(int i = 0; i < pg->numV; ++i)
    {
        printf("%c와 연결된 정점: ", i + 65);

        if(LFirst(&(pg->adjList[i]), &vx))
        {
            printf("%c ", vx +65);

            while(LNext(&(pg->adjList[i]), &vx))
                printf("%c ", vx +65);
        }

        printf("\n");
    }
}

int WhoIsPrecede(int data1, int data2)
{
    if(data1 < data2)
        return 0;
    else
        return 1;
}

// 두 번째 매개변수로 전달된 이름의 정점에 방문!
int VisitVertex(ALGraph* pg, int visitV)
{
    if(pg->visitInfo[visitV] == 0)    // visitV에 처음 방문일 때 '참인 if문
    {
        pg->visitInfo[visitV] = 1;    // visitV에 방문한 것으로 기록
        printf("%c ", visitV + 65);

        return TRUE;                  // 방문 성공!
    }

    return FALSE;                     // 방문 실패!
}

// BFS 기반으로 정의된 함수: 정점의 정보 출력
void BFShowGraphVertex(ALGraph* pg, int startV)
{
    Queue queue;
    int visitV = startV;
    int nextV;

    QueueInit(&queue);

    VisitVertex(pg, visitV);          // 시작 정점을 탐색한다.

    // 아래의 while문에서는 visitV와 연결된 모든 정점에 방문한다.
    while(LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
    {
        if(VisitVertex(pg, nextV) == TRUE)
            Enqueue(&queue, nextV);    // nextV에 방문했으니 큐에 저장


        while(LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
        {
            if(VisitVertex(pg, nextV) == TRUE)
                Enqueue(&queue, nextV);    // nextV에 방문했으니 큐에 저장
        }


        if(QIsEmpty(&queue) == TRUE)  // 큐가 비면 BFS 종료
            break;
        else
            visitV = Dequeue(&queue);   // 큐에서 하나 꺼내서 while문 다시 시작
    }

    memset(pg->visitInfo, 0, sizeof(int)* pg->numV);  // 탐색 정보 초기화
}