// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
#include <bits/stdc++.h>

using namespace std;


int read_input() {
    int _integer=0;
    char _char=0;

    while(_char<48){
        _char=getchar_unlocked();
    }

    while(_char>=48) {
        _integer=10*_integer+_char-48;
        _char=getchar_unlocked();
    }

    return _integer;
}


// This class represents a directed graph using
// adjacency list representation
class Graph
{
    int V;    // No. of vertices

    // Pointer to an array containing adjacency
    // lists
    list<int> *adj;
public:

    Graph(int V);  // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints BFS traversal from a given source s
    int BFS(int s, bool t,  vector <int> &city);
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

int Graph::BFS(int s, bool t, vector <int> &city)
{

    int num = s;
    int dis = 0;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;

    // Create a queue for BFS
    list<int> queue;

    // Mark the current node as visited and enqueue it
    visited[s] = true;
    int out = 0;
    queue.push_back(s);

    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
    long int c = city.size();

    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        
        out ++;
        for (int l = 0; l < c; l++){
            if(city[l] == s){
                dis = out;
                num = s;
            }
        }

        queue.pop_front();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

    if (t)
        return num;
    else
        return dis;
}

// Driver program to test methods of graph class
int main(){

    vector<int> fabric;
    int n = 0, f = 0, l = 0, r = 0, out = 0;
    n = read_input();
    f = read_input();
    Graph g(n);


    for (int i = 0; i < n - 1; ++i){
        l = read_input();
        r = read_input();
        g.addEdge(l, r);

    }


    for (int j = 0; j < f; j++){
        int b = 0;
        b = read_input();
        fabric.push_back(b);
    }


    int firstout = g.BFS(0, true, fabric);
    int secendout = g.BFS(0, false, fabric);

    cout << secendout;
}