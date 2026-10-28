#include <iostream>
using namespace std;

class Graph {
private:
    int vertices, adj[20][20];

public:
    Graph()
    {
        vertices = 0;

        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 20; j++)
                adj[i][j] = 0;
    }

    void createGraph()
    {
        int edges, origin, destination;

        cout << "\nEnter number of vertices: ";
        cin >> vertices;

        for(int i = 0; i < vertices; i++)
        {
            for(int j = 0; j < vertices; j++)
            {
                adj[i][j] = 0;
            }
        }

        cout << "Enter number of edges: ";
        cin >> edges;

        for(int i = 0; i < edges; i++)
        {
            cout << "Enter origin and destination: ";
            cin >> origin >> destination;

            adj[origin][destination] = 1;
            adj[destination][origin] = 1;
        }
    }

    void displayGraph()
    {
        cout << "\nAdjacency Matrix:\n";

        for(int i = 0; i < vertices; i++)
        {
            for(int j = 0; j < vertices; j++)
            {
                cout << adj[i][j] << " ";
            }

            cout << endl;
        }
    }

    void DFS()
    {
        // visited array
        int visited[20] = {0};

        // stack
        int stack[20];
        int top = -1;

        // initialize all vertices as not visited
        for(int i = 0; i < vertices; i++)
        {
            visited[i] = 0;
        }

        // Start DFS from vertex 0
        top++;
        stack[top] = 0;

        cout << "\nDFS Traversal: ";

        while(top != -1)
        {
            // Remove vertex from stack
            int current = stack[top];
            top--;

            // If vertex is not visited
            if(visited[current] == 0)
            {
                cout << current << " ";
                visited[current] = 1;

                // Add adjacent vertices to stack
                for(int i = vertices - 1; i >= 0; i--)
                {
                    if(adj[current][i] == 1 && visited[i] == 0)
                    {
                        top++;
                        stack[top] = i;
                    }
                }
            }
        }

        cout << endl;
    }
};

int main()
{
    Graph g;

    g.createGraph();

    g.displayGraph();

    g.DFS();

    return 0;
}