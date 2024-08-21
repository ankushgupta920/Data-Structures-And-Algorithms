#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void DFS(vector<vector<int>>& graph, int start) {
    int vertices = graph.size();
    vector<bool> visited(vertices, false);
    stack<int> stack;

    stack.push(start);

    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();

        if (!visited[current]) {
            cout << current << " ";
            visited[current] = true;

            for (int neighbor : graph[current]) {
                if (!visited[neighbor]) {
                    stack.push(neighbor);
                }
            }
        }
    }
}

int main() {
    vector<vector<int>> graph = {
        {1, 2},
        {0, 3, 4},
        {0, 4},
        {1},
        {1, 2}
    };

    cout << "DFS Traversal starting from vertex 0: ";
    DFS(graph, 0);
    cout << endl;

    return 0;
} 