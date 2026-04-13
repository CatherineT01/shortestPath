// core of program
// stores career paths as an adjaceny list, where each key is a vertext and its value is a list
// of neighboring nodes (creates using a struct)

#include "Graph.h"
#include <vector>
Graph::Graph(){}
void Graph::addVertex(string name){
	if (adjList.find(name) == adjList.end()) { // check if vertex does not exist
		adjList[name] = vector<Neighbor>(); // create an empty neighbor list
	}
	
}
void Graph::addEdge(string start, string destination, int weight){
	addVertex(start);
	addVertex(destination);
	for (const Neighbor& n : adjList[start]) {
		if (n.destination == destination) { // check for duplicate edge
			return; // do nothing if edge already exists
		}
	}
	Neighbor newNeighbor;// if no duplicate is found, create and add the neighbor
	newNeighbor.destination = destination;
	newNeighbor.weight = weight;
	adjList[start].push_back(newNeighbor);
}
void Graph::printVertices(){
	cout << "Available Career Paths: " << endl;
	for (const pair<string, vector<Neighbor>>& p : adjList) { // loop through adjacency list
		cout << p.first << endl;
	}
}
void Graph::printEdges(){
	cout << "Graph Connection with Weights: " << endl;
	for (const pair<string, vector<Neighbor>>& p : adjList) { // loop through vertex and its neighbor list
		for (const Neighbor& n : p.second) {
			cout << p.first << " -> " << n.destination << " (" << n.weight << " years)" << endl;
		}
	}
}
vector<Neighbor> Graph:: getNeighbors(string vertex){ // return list of neighbors for a given vertex
	addVertex(vertex); // make sure vertex exists, create if missing
	return adjList[vertex]; // return vector of neighbors
}