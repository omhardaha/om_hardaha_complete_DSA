#include <bits/stdc++.h>
using namespace std;
class Graph
{
private:
    int size;
    bool unDirected;
    vector<vector<pair<int, int>>> l;

public:
    Graph(int v, bool dir = true)
    {
        size = v;
        unDirected = dir;
        l = vector<vector<pair<int, int>>>(size);
    }
    void addEdge(int v, int u, int weight)
    {
        l[v].push_back({u, weight});
        if (unDirected)
        {
            l[u].push_back({v, weight});
        }
    }
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
    void topoSortHelper(int source, stack<int> &st, vector<bool> &visited)
    {
        visited[source] = true;
        for (auto i : l[source])
        {
            if (!visited[i.first])
            {
                topoSortHelper(i.first, st, visited);
            }
        }
        st.push(source);
    };
    vector<int> topoSortDFS()
    {
        stack<int> st;
        vector<bool> visited(size, false);
        for (int i = 0; i < size; i++)
        {
            if (!visited[i])
            {
                topoSortHelper(i, st, visited);
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
    stack<int> topoSortStack()
    {
        // this func returns stack of element
        stack<int> st;
        vector<bool> visited(size, false);
        for (int i = 0; i < size; i++)
        {
            if (!visited[i])
            {
                topoSortHelper(i, st, visited);
            }
        }
        return st;
    }

    vector<int> shortestPathInDAG(int source = 0)
    {
        //  for finding Shortest Path In Directed Weighted ACyclicGraphs
        //  Time Complexity = O(V + E)
        stack<int> topoStack = topoSortStack();
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

    vector<int> Dijkstras(int source = 0)
    {
        //  work in both directed or undirected
        //  Time Complexity = O(E + Vlog(V))
        //  not works for Negetive Weight
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

    vector<int> BellmanFord(int source = 0)
    {
        //  -> Time Complexity =  O(VE)
        //  -> work in both directed or undirected
        //  -> works for Negetive Weight
        //  -> not works if there is a Negetive Cycle (sum of cyle weight is less then 0)

        // -> addition point
        // -> if you hv to check negetive cycle run a loop after n-1 if there is a change means negetive cycle present https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1#
        vector<int> distance(size, 10000);
        distance[source] = 0;
        int n = size - 1;
        while (n--)
        {
            for (int i = 0; i < size; i++)
            {
                for (auto &node : l[i])
                {
                    if (distance[i] + node.second < distance[node.first])
                    {
                        distance[node.first] = distance[i] + node.second;
                    }
                }
            }
        }
        return distance;
    }
};

int main()
{
    Graph p(6, false);  // for making directed use 2nd params as false
    p.addEdge(0, 1, 5); // v,u, & weight
    p.addEdge(1, 5, -3);
    p.addEdge(1, 2, -2);
    p.addEdge(2, 4, 3);
    p.addEdge(3, 2, 6);
    p.addEdge(3, 4, -2);
    p.addEdge(5, 3, 1);
    p.printGraph();
    vector<int> dis = p.BellmanFord();
    for (auto i : dis)
    {
        cout << i << " ";
    }
    return 0;
};