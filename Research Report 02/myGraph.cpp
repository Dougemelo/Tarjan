#include "myGraph.h"

#include <utility>

typedef std::vector<Edge*> Graph;
typedef std::stack<Vertex*> Stack;

Vertex* createVertex(std::string s){
    auto* v = new Vertex;
    v->word = std::move(s);
    return v;
}
Edge* createEdge(Vertex *From, Vertex *To){
    Edge* e = new Edge;
    e->from = From;
    e->to = To;
    From->successor.push_back(To);
    To->predecessor.push_back(From);
    return e;
}