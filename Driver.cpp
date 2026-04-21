//-----------------------------------------------------------------------------------
// CS 355 SHORTEST PATH TO BECOMING A MILLIONAIRE 
// Authors: Adi, AJ, Catherine, Betsy
// Date: 4/21/2026
// File: Driver 
// Description: This program uses Dijkstra's algorithm to find the shortest career path
// to becoming a Millionaire. The user selects their current career level
// and the program calculates the fastest route based on years of experience.
//----------------------------------------------------------------------------------

#include<fstream>
#include <iomanip>
#include <string>
#include "graph.h"
#include "Queue.h"
#include "shortestpath.h"


int main() {
    Graph g;
    shortestpath sp;
    string filename, source, target;
    string line;

    cout << "==========================================" << endl;
    cout << "    Career Path to Millionaire Finder     " << endl;
    cout << "==========================================" << endl;

    cout << "\nEnter the input file name (xxx.txt): ";
    cin >> filename;
    ifstream inFile(filename.c_str());
    while (!inFile.is_open()) {
        cout << "Error: Could not open '" << filename << "'. Try again: ";
        cin >> filename;
        inFile.open(filename);
    }

    while (getline(inFile, line)) {
        size_t c1 = line.find(',');
        size_t c2 = line.find(',', c1 + 1);
        string start = line.substr(0, c1);
        string destination = line.substr(c1 + 1, c2 - c1 - 1);
        int weight = stoi(line.substr(c2 + 1));
        g.addEdge(start, destination, weight);
    }
    inFile.close();

    cout << "\n==============================================" << endl;
    g.PrintAdjacencyList();
    g.printEdges();


    char again;

    do {
    cout << "\nWhat is your current career level? Choose from the list:" << endl;
    g.printVertices();
    cout << "\nEnter your choice: ";
    cin >> source;


    source[0] = toupper(source[0]);
    for (int i = 1; i < source.length(); i++)
        source[i] = tolower(source[i]);


    target = "Millionaire";

    cout << "\n==============================================" << endl;
    cout << "  Finding your path to " << target << "..." << endl;
    cout << "==============================================" << endl << endl;

    sp.run(g, source, target);
    sp.printPath(source, target);

    cout << "\nWould you like to try a different starting level? (y/n): ";
    cin >> again;
    } while (again == 'y' || again == 'Y');

    cout << "\nGood luck on your journey to becomming a Millionaire! Goodbye!" << endl;

    return 0;
}