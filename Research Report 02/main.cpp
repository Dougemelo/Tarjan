#pragma "once"
#include "setup.h"
#include "Tarjan.h"

int main() {
    Graph *testGraph1 = testGraphOne();
    Graph *testGraph2 = testGraphTwo();
    Graph *testGraph3 = testGraphThree();
    Graph *testGraph4 = testGraphFour();

    printf("\n\tTEST GRAPH 01:\n");
    tarjan(testGraph1);
    printf("\n\tTEST GRAPH 02:\n");
    tarjan(testGraph2);
    printf("\n\tTEST GRAPH 03:\n");
    tarjan(testGraph3);
    printf("\n\tTEST GRAPH 04:\n");
    tarjan(testGraph4);

    deleteAll(testGraph1);
    deleteAll(testGraph2);
    deleteAll(testGraph3);
    deleteAll(testGraph4);
}
