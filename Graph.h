#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Neighbor {
	string destination;
	int weight;
};

struct Edge { // struct for addEdge from a .txt file
	string start;
	string end;
	int Inputweight;
};

class Graph {

	map<string, vector<Neighbor>> adjList;
	vector<vector<int>> adj_matrix;

public:
	Graph();
	void addVertex(string name); // add vertex to graph if it does not exist yet
	void addEdge(string start, string destination, int weight); // add directed edge
	void printVertices(); // print all vertices in the graph
	void printEdges(); // print all edges and their weights
	void PrintAdjacencyList();
	vector<Neighbor> getNeighbors(string vertex); // return list of neighbors for a given vertes
	vector<string> getVertices();
};
#endif 