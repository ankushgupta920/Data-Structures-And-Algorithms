#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX

// Function to find the shortest paths from a given source vertex
void dijkstra(vector<vector<pair<int, int>>> &graph, int source) {
    int V = graph.size();
    vector<int> dist(V, INF); // Initialize distances to infinity
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &neighbor : graph[u]) {
            int v = neighbor.first; 
            int weight = neighbor.second; 

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print shortest distances from source
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << ": " << dist[i] << endl;
    }
}

int main() {
    // Constructing a sample graph
    int V = 6; // Number of vertices
    vector<vector<pair<int, int>>> graph(V);

    // Adding edges to the graph (source, destination, weight)
    graph[0].push_back({1, 5}); // 0->1, weight 5
    graph[0].push_back({2, 3}); // 0->2, weight 3
    graph[1].push_back({3, 6}); // 1->3, weight 6
    graph[2].push_back({3, 2}); // 2->3, weight 2
    graph[2].push_back({4, 4}); // 2->4, weight 4
    graph[3].push_back({4, 6}); // 3->4, weight 6
    graph[3].push_back({5, 7}); // 3->5, weight 7
    graph[4].push_back({5, 3}); // 4->5, weight 3

    int source = 0; // Source vertex

    cout << "Graph constructed successfully.\n";
    cout << "Applying Dijkstra's algorithm...\n";

    dijkstra(graph, source);

    return 0;
}