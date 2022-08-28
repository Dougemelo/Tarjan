#pragma "once"
#include <stack>
#include <iostream>
#include "Tarjan.h"
#include "myGraph.h"

static int ID = 1;

int getID(){
    int result = ID;
    ID++;
    return result;
}

void tarjan(Graph* G){
    Stack s;
    for(int i=0; i<G->size(); i++){
        Vertex* v = G->at(i)->to;
        if(v->index==0){
            strongConnect(&s, v);
        }
    }
    ID = 1;
}

void strongConnect(Stack* s, Vertex* v){
    int thisID = getID();
    v->index = thisID;
    v->lowLink = thisID;

    s->push(v);
    v->onStack = true;

    for(Vertex* w : v->successor){
        if(w->index==0){
            strongConnect(s, w);
            v->lowLink = std::min(v->lowLink, w->lowLink);
        } else if(w->onStack){
            v->lowLink = std::min(v->lowLink, w->lowLink);
        }
    }
    if(v->lowLink == v->index){
        while(!s->empty() && v->lowLink == s->top()->lowLink) {
            Vertex *output = s->top();
            output->onStack = false;
            s->pop();
            std::cout<<output->word<<" has index "<<output->index<<"."<<output->lowLink<<"\t|\t";
        }
        std::cout<<"\n";
    }
}
