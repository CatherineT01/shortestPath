#ifndef _SHORTESTPATH_H_
#define _SHORTESTPATH_H_
#include "graph.h"
#include "Queue.h"
class shortestpath {
private:
    map<string, int>    dist;   // shortest known distnce to the vertex
    map<string, string> prev;   //best prev path

public:
    // runs the algorithm — needs the graph and a starting vertex
    void run(Graph& graph, string start, string target);

    // prints the shortest path from start to a specific target
    void printPath(string start, string target);

};

#endif