#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to perform BFS traversal
void BFS(vector<vector<int>>& graph, int start) {
    int vertices = graph.size();
    vector<bool> visited(vertices, false); // Mark all vertices as not visited

    // Create a queue for BFS
    queue<int> queue;

    // Mark the current node as visited and enqueue it
    visited[start] = true;
    queue.push(start);

    while (!queue.empty()) {
        // Dequeue a vertex from queue and print it
        int current = queue.front();
        cout << current << " ";
        queue.pop();

        
        for (int i = 0; i < graph[current].size(); ++i) {
            int neighbor = graph[current][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {1, 2},     // Adjacent vertices of vertex 0
        {0, 3, 4},  // Adjacent vertices of vertex 1
        {0, 4},     // Adjacent vertices of vertex 2
        {1},        // Adjacent vertices of vertex 3
        {1, 2}      // Adjacent vertices of vertex 4
    };

    cout << "BFS Traversal starting from vertex 0: ";
    BFS(graph, 0); // Start BFS from vertex 0
    cout << endl;

    return 0;
}