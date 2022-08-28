#pragma "once"

#include <algorithm>
#include "Tarjan.h"
#include "myGraph.h"
#ifndef RESEARCH_PAPER_02_SETUP_H
#define RESEARCH_PAPER_02_SETUP_H

Graph* testGraphOne(){
    // Passed
    Vertex* one = createVertex("one");
    Vertex* two = createVertex("two");
    Vertex* three = createVertex("three");
    Vertex* four = createVertex("four");
    Vertex* five = createVertex("five");
    Vertex* six = createVertex("six");
    Vertex* seven = createVertex("seven");
    Vertex* eight  = createVertex("eight");

    Graph* g = new Graph;
    g->push_back(createEdge(one, five)); //e1
    g->push_back(createEdge(five, two)); //e2
    g->push_back(createEdge(two, one)); //e3

    g->push_back(createEdge(six, five)); //e4
    g->push_back(createEdge(six, two)); //e5
    g->push_back(createEdge(three, two)); //e6

    g->push_back(createEdge(seven, six)); //e7
    g->push_back(createEdge(six, seven)); //e8
    g->push_back(createEdge(seven, three)); //e9

    g->push_back(createEdge(three, four)); //e10
    g->push_back(createEdge(four, three)); //e11

    g->push_back(createEdge(eight, seven)); //e12
    g->push_back(createEdge(eight, eight)); //e13

    g->push_back(createEdge(eight, four)); //e14

    return g;
}

Graph* testGraphTwo(){
    Vertex *shout = createVertex("shout");
    Vertex *doubt = createVertex("doubt");

    Vertex *sun = createVertex("sun");
    Vertex *fun = createVertex("fun");

    Vertex *rounds = createVertex("rounds");
    Vertex *frowns = createVertex("frowns");

    Vertex *app = createVertex("app");
    Vertex *zap = createVertex("zap");

    Graph *g = new Graph;

    g->push_back(createEdge(shout, doubt));
    g->push_back(createEdge(doubt, shout));

    g->push_back(createEdge(sun, fun));
    g->push_back(createEdge(fun, sun));

    g->push_back(createEdge(rounds, frowns));
    g->push_back(createEdge(frowns, rounds));

    g->push_back(createEdge(app, zap));
    g->push_back(createEdge(zap, app));

    g->push_back(createEdge(sun, shout));
    g->push_back(createEdge(rounds, sun));
    g->push_back(createEdge(zap, frowns));
}

Graph* testGraphThree(){
    Vertex* a = createVertex("a");
    Vertex* b = createVertex("b");
    Vertex* c = createVertex("c");
    Vertex* d = createVertex("d");
    Vertex* e = createVertex("e");
    Vertex* f = createVertex("f");
    Vertex* g = createVertex("g");
    Vertex* h = createVertex("h");

    Graph* newGraph = new Graph;

    newGraph->push_back(createEdge(a, b));
    newGraph->push_back(createEdge(b, e));
    newGraph->push_back(createEdge(b, f));
    newGraph->push_back(createEdge(b, c));
    newGraph->push_back(createEdge(c, d));
    newGraph->push_back(createEdge(c, g));
    newGraph->push_back(createEdge(d, c));
    newGraph->push_back(createEdge(d, h));
    newGraph->push_back(createEdge(e, a));
    newGraph->push_back(createEdge(e, f));
    newGraph->push_back(createEdge(f, g));
    newGraph->push_back(createEdge(g, f));
    newGraph->push_back(createEdge(h, g));
    newGraph->push_back(createEdge(h, d));

    return newGraph;
};

void deleteAll(Graph* g){
    std::vector<Vertex*> memVector;
    for(int i=0; i<g->size(); i++){
        bool trueTo = std::count(memVector.begin(), memVector.end(),g->at(i)->to);
        bool trueFrom = std::count(memVector.begin(), memVector.end(),g->at(i)->from);
        if(!trueTo){
            memVector.push_back(g->at(i)->to);
        }
        if(!trueFrom){
            memVector.push_back(g->at(i)->from);
        }
    }
    for(int i=0; i<memVector.size(); i++){
        delete memVector.at(i); //delete all vertices
    }

    for(int i=0; i<g->size(); i++){
        delete g->at(i); //delete edge
    }
    delete g;
}

#endif //RESEARCH_PAPER_02_SETUP_H
