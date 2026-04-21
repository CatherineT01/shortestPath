#include "Graph.h"
#include <vector>
//------------------------------------------------------------
// Method:      Graph (constructor)
// Author:      Catherine
// Description: Initializes an empty graph with no vertices or edges
// Incoming:    no data
// Outgoing:    no data
//------------------------------------------------------------
Graph::Graph(){}

//------------------------------------------------------------
// Method:      addVertex
// Author:      Catherine
// Description: Adds a new vertex to the graph if it does not already exist
// Incoming:    namem the name of the vertex to add (string)
// Outgoing:    no data
//------------------------------------------------------------
void Graph::addVertex(string name){
	//fixing the case

	if (adjList.find(name) == adjList.end()) { // check if vertex does not exist
		adjList[name] = vector<Neighbor>(); // create an empty neighbor list
	}
}

//------------------------------------------------------------
// Method:      addEdge
// Author:      Catherine
// Description: Adds a directed edge between two vertices with a given weight.
//              normalizes capitalization of vertex names, creates vertices if
//              they do not exist, and ignores duplicate edges
// Incoming:    start - the source vertex (string)
//              destination - the destination vertex (string)
//              weight, the cost of the edge in years (int)
// Outgoing:    no data
//------------------------------------------------------------
void Graph::addEdge(string start, string destination, int weight){
	
	//fixing the case for vertices
	start[0] = toupper(start[0]);
	for (int i = 1; i < start.length(); i++)
		start[i] = tolower(start[i]);
	
	destination[0] = toupper(destination[0]);
	for (int i = 1; i < destination.length(); i++)
		destination[i] = tolower(destination[i]);

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

//------------------------------------------------------------
// Method:      printVertices
// Author:      Catherine
// Description: Prints all vertices currently in the graph to the console
// Incoming:    no data
// Outgoing:    no data
//------------------------------------------------------------
void Graph::printVertices(){
	cout << "Available Career Paths: " << endl;
	for (const pair<string, vector<Neighbor>>& p : adjList) { // loop through adjacency list
		cout << p.first << endl;
	}
}

//------------------------------------------------------------
// Method:      printEdges
// Author:      Catherine
// Description: Prints all edges in the graph with their source, destination,
//              and weight to the console
// Incoming:    no data
// Outgoing:    no data
//------------------------------------------------------------
void Graph::printEdges(){
	cout << "Graph Connection with Weights: " << endl;
	for (const pair<string, vector<Neighbor>>& p : adjList) { // loop through vertex and its neighbor list
		for (const Neighbor& n : p.second) {
			cout << p.first << " -> " << n.destination << " (" << n.weight << " years)" << endl;
		}
	}
}

//------------------------------------------------------------
// Method:      PrintAdjacencyList
// Author:      Catherine
// Description: Prints the adjacency matrix of the graph to the console
// Incoming:    none
// Outgoing:    none
//------------------------------------------------------------
void Graph::PrintAdjacencyList(){

	cout << "Adjacency matrix for current graph" << endl;
	int n = adj_matrix.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << adj_matrix[i][j] << " ";
		}
		cout << endl;
	}
}

//------------------------------------------------------------
// Method:      getNeighbors
// Author:      Catherine
// Description: Returns a list of all neighboring vertices for a given vertex.
//              creates the vertex if it does not already exist
// Incoming:    vertex - the name of the vertex to look up (string)
// Outgoing:    vector of Neighbor objects connected to the given vertex
//------------------------------------------------------------
vector<Neighbor> Graph:: getNeighbors(string vertex){ // return list of neighbors for a given vertex
	addVertex(vertex); // make sure vertex exists, create if missing
	return adjList[vertex]; // return vector of neighbors
}


//------------------------------------------------------------
// Method:      getVertices
// Author:      Catherine
// Description: Returns a list of all vertex names currently in the graph
// Incoming:    no data
// Outgoing:    vector of strings containing all vertex names
//------------------------------------------------------------
vector<string> Graph::getVertices(){
		vector<string> vertices;

		for (const pair<string, vector<Neighbor>>& p : adjList) {
			vertices.push_back(p.first); // store the vertex name
		}

		return vertices;
}
