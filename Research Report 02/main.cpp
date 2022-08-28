#pragma "once"
#include "setup.h"
#include "Tarjan.h"

int main() {
    Graph *f = testGraphOne();
    Graph *g = testGraphTwo();
    Graph *h = testGraphThree();

    tarjan(f);
    printf("\n");
    tarjan(g);
    printf("\n");
    tarjan(h);

    deleteAll(f);
    deleteAll(g);
    deleteAll(h);
}
