#ifndef GRAPH_H_
#define GRAPH_H_
#include<iostream>
#include<vector>
#include<list>
#include<map>

using namespace std;

/*
class graph {
	vector<vector<int> > adj_matrix;

public:
	graph(int n) {
		adj_matrix = vector<vector<int> >(n, vector<int>(n, 0));
	}

	void addEdge(int u, int v) {
		adj_matrix[u][v] = 1;

		adj_matrix[v][u] = 1;
		cout << "added edge " << u << " , " << v << " to the matrix" << endl;

	}

	void print() {
		cout << "Adjecency Matrix for current graph" << endl;

		int n = adj_matrix.size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << adj_matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};
*/

class Graph {
	map<int, list<int> >
		adjList; // Adjacency list to store the graph

public:
	// Function to add an edge between vertices u and v of
	// the graph
	void addEdge(int u, int v)
	{
		// Add edge from u to v
		adjList[u].push_back(v);
		// Add edge from v to u because the graph is
		// unidirected
		adjList[v].push_back(u);
	}

	void print()
	{
		cout << "Adjacency list for the Graph: " << endl;
		// Iterate over each vertex
		for (auto i : adjList) {
			// Print the vertex
			cout << i.first << " -> ";
			// Iterate over the connected vertices
			for (auto j : i.second) {
				// Print the connected vertex
				cout << j << " ";
			}
			cout << endl;
		}
	}
};
#endif
