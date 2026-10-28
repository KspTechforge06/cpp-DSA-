#include <iostream>
using namespace std;
class Node {
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
}

// visted array 
int visited[20];
int stack[20];
int top = -1;
//intialize all the vertices as not visited 
top++ 
stack[top] = 0;

int main()
{
    Graph g;
    g.createGraph();
    return 0;
};