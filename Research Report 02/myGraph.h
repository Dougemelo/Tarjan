#pragma "once"
#include <vector>
#include <string>
#include <stack>

#ifndef RESEARCH_REPORT_02_MYGRAPH_H
#define RESEARCH_REPORT_02_MYGRAPH_H

// the words Node and Vertex
// are interchangeable
struct Vertex{
    // the key value of the node
    std::string word = "";
    // member variables to help tarjan
    int index = 0;
    int lowLink = 0;
    bool onStack = false;
    // a list of predecessor and successor nodes
    std::vector<Vertex*> predecessor;
    std::vector<Vertex*> successor;
};

// connects node from to node to
struct Edge{
    // initialized to nullptr
    Vertex* from = nullptr;
    Vertex* to = nullptr;
};

// Graph is an adjacency list, the Edge has
// its two nodes as member variables
typedef std::vector<Edge*> Graph;

// standard library stack for nodes
typedef std::stack<Vertex*> Stack;

Vertex* createVertex(std::string s);
Edge* createEdge(Vertex *From, Vertex *To);

#endif //RESEARCH_REPORT_02_MYGRAPH_H
