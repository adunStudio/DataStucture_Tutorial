/*
 * 깊이 우선 탐색(Depth First Search: DFS)
 * - 한 사람에게만 연락을 한다.
 * - 연락할 사람이 없으면, 자신에게 연락할 사람에게 이를 알린다.
 * - 처음 연락을 시작한 사람의 위치에서 연락은 끝이난다.
 */


#ifndef __AL_GRAPH_DFS__
#define __AL_GRAPH_DFS__

#include "DLinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};

typedef struct _ual
{
    int numV;
    int numE;
    List* adjList;
    int* visitInfo;

} ALGraph;

// 그래프의 초기화
void GraphInit(ALGraph* pg, int nv);

// 그래프의 리소스 해제
void GraphDestory(ALGraph* pg);

// 간선의 추가
void AddEdge(ALGraph* pg, int fromV, int toV);

// 간선의 정보 출력
void ShowGraphEdgeInfo(ALGraph* pg);

// 정점의 정보 출력: Depth First Search 기반
void DFShowGraphVertex(ALGraph* pg, int startV);

#endif