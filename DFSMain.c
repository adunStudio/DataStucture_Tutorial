#include <stdio.h>
#include "ALGraphDFS.h"

int main()
{
    ALGraph graph;

    GraphInit(&graph, 7);

    AddEdge(&graph, A, B);
    AddEdge(&graph, A, D);
    AddEdge(&graph, B, C);
    AddEdge(&graph, D, C);
    AddEdge(&graph, D, E);
    AddEdge(&graph, E, F);
    AddEdge(&graph, E, G);

    ShowGraphEdgeInfo(&graph);

    DFShowGraphVertex(&graph, A);
    printf("\n");
    DFShowGraphVertex(&graph, B);
    printf("\n");
    DFShowGraphVertex(&graph, C);
    printf("\n");
    DFShowGraphVertex(&graph, D);
    printf("\n");
    DFShowGraphVertex(&graph, E);
    printf("\n");
    DFShowGraphVertex(&graph, F);
    printf("\n");

    return 1;
}