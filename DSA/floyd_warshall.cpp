#include <iostream>
#define INF 2147483647
using namespace std;

void floydWarshall(int graph[4][4], int V) {
    
    int dist[V][V];

    // Initialize the distance matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Add all vertices one by one to the set of intermediate vertices.
    // The outer loop does the same thing as Floyd-Warshall
    for (int k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < V; i++) {
            // Pick all vertices as destination one by one
            for (int j = 0; j < V; j++) {
                // If vertex k is on a shorter path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // Print the shortest distance matrix
    cout << "The following matrix shows the shortest distances"
            " between every pair of vertices \n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    
    int graph[4][4] = {{0, 2, INF, INF},
                       {1, 0, 3, INF},
                       {INF, INF, 0, INF},
                       {3, 5, 4, 0}};
    floydWarshall(graph, 4);
    return 0;
}
/*

*Explanation:*

- The code starts by including necessary header files and defining INF for representing infinity.
- The floydWarshall function takes a graph represented as a 2D array graph and the number of vertices V as input.
- It creates a dist matrix to store the shortest distances.
- The algorithm iterates through all possible intermediate vertices k and updates the dist matrix if a shorter path is found.
- The final dist matrix contains the shortest distances between all pairs of vertices.

*Key points:*

- The time complexity of this implementation is O(V^3).
- The space complexity is O(V^2) for the dist matrix.
- The code uses INF to represent unreachable vertices.

This implementation provides a clear and efficient way to implement the Floyd-Warshall algorithm in C++.
*/