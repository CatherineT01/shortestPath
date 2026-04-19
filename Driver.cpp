// entry point. handles input/output, initializes the graph with verticies and edges. calls the 
// algorithm and displays the result
#include<fstream>
#include <iomanip>
#include <string>
#include "graph.h"
#include "Queue.h"
#include "shortestpath.h"

int main() {
    Graph g;
    Queue q;
    shortestpath sp;
    string source, target;
 
    vector<Edge> edges;
    string line;
    ifstream inFile("graph.txt");

    // check if file is open
    if (!inFile.is_open()) {
        cout << "Unable to open file" << endl;
        return 1;
    }

    while (getline(inFile, line)) {
        size_t c1 = line.find(','); // find first comma
        size_t c2 = line.find(',', c1 + 1); // find second comma
        string start = line.substr(0, c1); // get start
        string destination = line.substr(c1 + 1, c2 - c1 - 1); // get destination
        int weight = stoi(line.substr(c2 + 1)); // get weight as an integer

        g.addEdge(start, destination, weight); // add edge to graph
    } 
    inFile.close(); // close file

 
    cout << "==============================================" << endl;
    g.PrintAdjacencyList();
    g.printEdges();
    g.printVertices();
    q.printQueue();


    source = "Bachelors";
    target = "SMP";

    sp.run(g, source, target);
    sp.printPath(source, target);


    return 0;
}