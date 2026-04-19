#include "shortestpath.h"

void shortestpath::run(Graph& graph, string start, string target)
{
    dist.clear();
    prev.clear();

    // Initialize //my code wasnt working at first so the chat told me toa dd this
    for (const string& v : graph.getVertices()) {
        dist[v] = INT_MAX; //basically infinity
        prev[v] = "";//empty or null
    }
    dist[start] = 0;

    Queue pq;
    QueueNode current;
    string u;
    pq.enqueue(start, 0);

    while (!pq.isEmpty()) {

        current = pq.dequeue();
        u = current.vertex;
        if (u == target) { //If the target node is reached we break the loop
            break;
        }
        // Get neighbors
        vector<Neighbor> neighbors = graph.getNeighbors(u);

        for (const Neighbor& n : neighbors) {
            string v = n.destination;
            int weight = n.weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                prev[v] = u;

                pq.enqueue(v, dist[v]);
            }
        }
    }
}

void shortestpath::printPath(string start, string target)
{
    // check if target is reachable
    // .find() and .end() are both included in Map library
    //.find() will .end() if the element is not found in the map? if that makes sense
    if (dist.find(target) == dist.end() || dist[target] == INT_MAX) {
        cout << "No path from " << start << " to " << target << endl;
        return;
    }

    vector<string> path;
    string current = target;

    // backtrack using prev map
    while (current != "") {
        path.push_back(current);

        // if we reached start, stop
        if (current == start) break;

        current = prev[current];
    }

    // if start is not actually in path, no valid route
    if (path.back() != start) {
        cout << "No valid path found from " << start << " to " << target << endl;
        return;
    }

    // reverse path (target -> start becomes start -> target)
    reverse(path.begin(), path.end());

    // print path safely (ASCII only)
    cout << "Shortest path from " << start << " to " << target << ": ";

    for (int i = 0; i < path.size(); i++) {
        cout << path[i];

        if (i != path.size() - 1) {
            cout << " -> ";
        }
    }

    cout << endl;

    cout << "Total cost: " << dist[target] << endl;
}

