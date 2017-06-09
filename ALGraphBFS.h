/*
 * 너비 우선 탐색(Breadth First Search: BFS)
 * DFS가 한 사람에게 연락을 취하는 방식이라면, BFS는 자신에게 연결된 모든 사람에게 연락을 취하는 방법
 */

#include "DLinkedList.h"

enum {A, B, C, D, E, F, G, H, I, J};    // 정점의 이름들을 상수화

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

// 정점의 정보 출력: Breadth First Search 기반
void BFShowGraphVertex(ALGraph* pg, int startV);
