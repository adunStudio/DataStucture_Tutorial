#include <stdio.h>
#include "ALGraphKruskal.h"

int main()
{
    ALGraph graph;

    GraphInit(&graph, 6);

    AddEdge(&graph, A, B, 9);
    AddEdge(&graph, A, B, 9);
    AddEdge(&graph, A, B, 9);
    AddEdge(&graph, A, B, 9);
    AddEdge(&graph, A, B, 9);
    AddEdge(&graph, A, B, 9);

    return 1;
}