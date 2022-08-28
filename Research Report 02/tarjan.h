#pragma "once"
//
// Created by xdoug on 8/26/2022.
//

#ifndef RESEARCH_PAPER_02_TARJAN_H
#define RESEARCH_PAPER_02_TARJAN_H

#include <stack>
#include <vector>
#include <iostream>
#include "myGraph.h"


int getID();
void strongConnect(Stack* s, Vertex* v);
void tarjan(Graph* G);


#endif //RESEARCH_PAPER_02_TARJAN_H
