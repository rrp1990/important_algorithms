#include <iostream>
#include <list>
#include <queue>

//Theory link http://www.codeproject.com/Articles/32212/Introduction-to-Graph-with-Breadth-First-Search-BF


using namespace std;

class graph
{
    int V; /* no of vertices*/
    list<int> *adj;

public:
    graph(int num_vert)
    {
        V = num_vert;
        adj = new list<int>[V];
    }

    ~graph(){delete[] adj;}

    void directed_add_edge(int node1, int node2);
    void undirected_add_edge(int node1, int node2);
    void BFS(int v);
    //void display();

};

void graph::BFS(int start_vertex)
{
    queue<int> mqueue;
    bool *visited = new bool[V];

    for(int i=0; i<V; i++)
    {
        visited[i] = false;
    }

    cout << start_vertex << " ";
    visited[start_vertex] = true;
    //mqueue.push(adj[start_vertex].front());
    mqueue.push(start_vertex);

    while(!mqueue.empty())
    {
        int v = mqueue.front();

        for(list<int>::iterator i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if(!visited[*i])
            {
                cout << *i << " ";
                mqueue.push(*i);
                visited[*i] = true;
            }

        }
        mqueue.pop();

    }

}

void graph::directed_add_edge(int node1, int node2)
{
    if((node1 < V) && (node2 < V))
    {
        adj[node1].push_back(node2);
        //adj[node2].push_back(node1);
    }

}

void graph::undirected_add_edge(int node1, int node2)
{
    if((node1 < V) && (node2 < V))
    {
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }

}

int main()
{
    graph mygraph(6);

    cout << "Directed Graph -> \n";
    mygraph.directed_add_edge(0,1);
    mygraph.directed_add_edge(0,2);
    mygraph.directed_add_edge(0,3);
    mygraph.directed_add_edge(1,4);
    mygraph.directed_add_edge(1,5);
    mygraph.directed_add_edge(2,5);

    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    mygraph.BFS(1);

    cout << "\nUndirected graph \n";
    mygraph.undirected_add_edge(0,1);
    mygraph.undirected_add_edge(0,2);
    mygraph.undirected_add_edge(0,3);
    mygraph.undirected_add_edge(1,4);
    mygraph.undirected_add_edge(1,5);
    mygraph.undirected_add_edge(2,5);

    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    mygraph.BFS(1);


}
