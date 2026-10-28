// 7 A Create a graph and implement DFS using adjacency matrix
#include <iostream>
using namespace std;

int graph[20][20];
int visited[20];
int n;

void createGraph()
{
    int edges, u, v;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    // Initialize matrix
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;

        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    cout << "Enter edges (vertex1 vertex2):\n";

    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v;

        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

void DFS(int vertex)
{
    cout << vertex << " ";
    visited[vertex] = 1;

    for (int i = 0; i < n; i++)
    {
        if (graph[vertex][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int start;

    createGraph();

    cout << "Enter starting vertex (0 to " << n - 1 << "): ";
    cin >> start;

    cout << "DFS Traversal: ";
    DFS(start);

    // Visit remaining disconnected vertices
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            DFS(i);
        }
    }

    cout << endl;

    return 0;
}
