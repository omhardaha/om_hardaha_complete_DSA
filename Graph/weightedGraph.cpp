#include <bits/stdc++.h>
using namespace std;
class Graph
{
private:
    int size;
    bool unDirected;
    vector<pair<int, int>> *l;

public:
    // Graph Constructor
    //  Note - Use second argument as false if use want to create directed graph
    Graph(int v, bool dir = true)
    {
        size = v;
        unDirected = dir;
        l = new vector<pair<int, int>>[v];
    }

    // adding edge
    void addEdge(int v, int u, int weight)
    {
        l[v].push_back({u, weight});
        if (unDirected)
        {
            l[u].push_back({v, weight});
        }
    }

    // printing Graph
    void printGraph()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << "-->";
            for (auto i : l[i])
            {
                cout << i.first << "(" << i.second << ") ";
            }
            cout << endl;
        }
    }

    // ----------Topological Sort Using DFS-------------------
    void topologicalSortDfsHelper(int source, stack<int> &st, vector<bool> &visited)
    {
        visited[source] = true;
        for (auto i : l[source])
        {
            if (!visited[i.first])
            {
                topologicalSortDfsHelper(i.first, st, visited);
            }
        }
        st.push(source);
    };
    vector<int> topologicalSortDfs()
    {
        stack<int> st;
        vector<bool> visited(size, false);
        for (int i = 0; i < size; i++)
        {
            if (!visited[i])
            {
                topologicalSortDfsHelper(i, st, visited);
            }
        }
        vector<int> topoList;
        while (!st.empty())
        {
            topoList.push_back(st.top());
            st.pop();
        }
        return topoList;
    }
    stack<int> topologicalSortDfsStack()
    {
        // this func returns stack of element
        stack<int> st;
        vector<bool> visited(size, false);
        for (int i = 0; i < size; i++)
        {
            if (!visited[i])
            {
                topologicalSortDfsHelper(i, st, visited);
            }
        }
        return st;
    }

    //           🧨🧨🧨 Shortest Path (Weighted) 🧨🧨🧨
    //   1. Topological Sort Methods
    vector<int> shortestPathInDAG(int source = 0)
    {
        //  for finding Shortest Path In Weighted Directed ACyclicGraphs
        //  Time Complexity = O(V + E)
        stack<int> topoStack = topologicalSortDfsStack();
        vector<int> distance(size, INT_MAX);
        distance[source] = 0;
        while (!topoStack.empty())
        {
            int node = topoStack.top();
            topoStack.pop();
            if (distance[node] != INT_MAX)
            {
                for (auto i : l[node])
                {
                    if (distance[i.first] > i.second + distance[node])
                    {
                        distance[i.first] = i.second + distance[node];
                    }
                }
            }
        }
        return distance;
    }

    //   2. Bellman-Ford
    //  Time Complexity =  O(VE)

    //  3. Dijkstra's Algorithm
    vector<int> DijkstrasAlgorithmShortestPathInUndirectedGraphs(int source = 0)
    {
        //  for finding Shortest Path In Weighted Undirected Graphs
        //  Note - Dijkstra's Algorithm not works for negetive Weight
        //  Time Complexity = O(E + Vlog(V))
        vector<int> distance(size, INT_MAX);
        distance[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        min_heap.push({0, source});
        while (!min_heap.empty())
        {
            int node = min_heap.top().second;
            int pathLength = min_heap.top().first;
            min_heap.pop();
            for (auto i : l[node])
            {
                if (distance[i.first] > pathLength + i.second)
                {
                    distance[i.first] = pathLength + i.second;
                    min_heap.push({distance[i.first], i.first});
                }
            }
        }
        return distance;
    }

    //               🧨🧨🧨Minimum Spanning Tree 🧨🧨🧨
};
int main()
{
    Graph p(7);         // for making directed use 2nd params as false
    p.addEdge(1, 5, 4); // v,u, & weight
    p.addEdge(1, 2, 1);
    p.addEdge(2, 3, 9);
    p.addEdge(5, 6, 3);
    p.addEdge(5, 4, 6);

    p.printGraph();
    vector<int> m = p.DijkstrasAlgorithmShortestPathInUndirectedGraphs(1);
    for (auto i : m)
        cout << i << " ";
    return 0;
}