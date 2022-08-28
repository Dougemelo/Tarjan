#pragma "once"
#include <vector>
#include <string>
#include <stack>

#ifndef RESEARCH_REPORT_02_MYGRAPH_H
#define RESEARCH_REPORT_02_MYGRAPH_H

struct Vertex{
    std::string word = "";

    int index = 0;
    int lowLink = 0;
    bool onStack = false;
    std::vector<Vertex*> predecessor;
    std::vector<Vertex*> successor;
};

struct Edge{
    Vertex* from = nullptr;
    Vertex* to = nullptr;
};

typedef std::vector<Edge*> Graph;
typedef std::stack<Vertex*> Stack;
Vertex* createVertex(std::string s);
Edge* createEdge(Vertex *From, Vertex *To);

#endif //RESEARCH_REPORT_02_MYGRAPH_H
