#include <iostream>
#include <vector>
using namespace std;

class Graph
{
    int V;                       // Number of vertices
    vector<vector<int>> adjList; // Adjacency list

public:
    Graph(int vertices)
    {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        // adjList[v].push_back(u); // If graph is undirected
    }

    void printGraph()
    {
        int count = 0;
        for (int i = 0; i < V; ++i)
        {   
            cout << "Adjacency list of vertex " << i << ": ";
            for (int j : adjList[i])
                cout << j << " ";
                count++;
            cout << endl;
        }
        cout << count <<endl;
    }
};

int main()
{
    int V = 3;     // Number of vertices
    Graph g(V); // Create a graph with 5 vertices

    // Add some edges
    // 1
    // g.addEdge(1, 2);
    // g.addEdge(1, 7);
    // g.addEdge(1, 8);
    // // 2
    // g.addEdge(2, 3);
    // g.addEdge(2, 6);
    // // 3
    // g.addEdge(3, 4);
    // g.addEdge(3, 5);
    // // 8
    // g.addEdge(8, 9);
    // g.addEdge(8, 12);
    // // 9
    // g.addEdge(9, 10);
    // g.addEdge(9, 11);

    g.addEdge(0 , 1);
    g.addEdge(1 , 2);
    g.addEdge(2 , 0);


    // Print the graph
    g.printGraph();

    return 0;
}