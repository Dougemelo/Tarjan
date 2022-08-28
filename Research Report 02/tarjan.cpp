#pragma "once"
#include <stack>
#include <iostream>
#include "Tarjan.h"
#include "myGraph.h"

// static num in memory to be
// tied to a Node at index and lowLink
static int ID = 1;
int getID(){
    int result = ID;
    ID++;
    return result;
}

void printVertex(Vertex* output){
    std::cout<<output->word<<" has index "<<output->index<<"."<<output->lowLink<<"\t|\t";
}

void tarjan(Graph* G){
    // create a stack to hold Nodes
    Stack s;
    // loop over every edge in the graph
    for(int i=0; i<G->size(); i++){
        // grab the vertex
        Vertex* v = G->at(i)->to;
        // has it been analyzed yet?
        if(v->index==0){
            // if not, call strongConnect pass
            // to it the stack and the vertex
            strongConnect(&s, v);
        }
    }
    // the algorithm has completed for this
    // graph, so we may reset the static ID
    ID = 1;
}

void strongConnect(Stack* s, Vertex* v){
    // apply the ID to index and lowLink
    int thisID = getID();
    v->index = thisID;
    v->lowLink = thisID;

    // put this vertex on the stack
    s->push(v);
    v->onStack = true;

    // analyze the Vertex v's successor w
    for(Vertex* w : v->successor){
        // has w been analyzed yet?
        if(w->index==0){
            // if so strongConnect w
            strongConnect(s, w);
            // reduce the lowLink of v to the least of
            // v's lowLink or w's
            v->lowLink = std::min(v->lowLink, w->lowLink);
        }
        // otherwise, if w is already in the stack
        else if(w->onStack){
            // just reduce lowLink in the same way
            v->lowLink = std::min(v->lowLink, w->lowLink);
        }
    }
    // if we have traversed back to start
    // of the strongly connected component...
    if(v->lowLink == v->index){
        // while the stack is not empty, and we're still working
        // with the same set of strongly connected components
        while(!s->empty() && v->lowLink == s->top()->lowLink) {
            // pop the stack and save it to output
            Vertex *output = s->top();
            output->onStack = false;
            s->pop();
            // print output
            printVertex(output);
        }
        std::cout<<"\n";
    }
}
