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

    //                🧨🧨🧨 Minimum Spanning Tree 🧨🧨🧨
    Graph PrimsAlgorithm(int head)
    {
        // Approach - Initially Select the Smallest One And Always Select the Connected Smallest One's
        vector<int> perent(size, -1);
        perent[0] = 0;
        vector<int> distance(size, INT_MAX);
        distance[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        min_heap.push({0, 0});
        vector<bool> visited(size, false);

        while (!min_heap.empty())
        {
            int p = min_heap.top().second;
            min_heap.pop();
            visited[p] = true;
            int diss = 0;
            for (auto i : l[p])
            {
                int node = i.first;
                if (!visited[node] && distance[node] > i.second)
                {
                    distance[node] = i.second;
                    min_heap.push({i.second, node});
                    perent[node] = p;
                }
            }
        }
        // calculate all distance
        // int ans = 0;
        // for (int i = 0; i < size; i++)
        // {
        //     ans += distance[i];
        // }
        // return ans;

        Graph m(size);
        for (int i = 0; i < perent.size(); i++)
        {
            if (i != head)
            {
                m.addEdge(i, perent[i], distance[i]);
            }
        }
        return m;
    }

    int PrimsAlgorithmMinSpanningTree()
    {
        vector<int> perent(size, -1);
        perent[0] = 0;
        vector<int> distance(size, INT_MAX);
        distance[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        min_heap.push({0, 0});
        vector<bool> visited(size, false);

        while (!min_heap.empty())
        {
            int p = min_heap.top().second;
            min_heap.pop();
            visited[p] = true;
            int diss = 0;
            for (auto i : l[p])
            {
                int node = i.first;
                if (!visited[node] && distance[node] > i.second)
                {
                    distance[node] = i.second;
                    min_heap.push({i.second, node});
                    perent[node] = p;
                }
            }
        }
        // calculate all distance
        int ans = 0;
        for (int i = 0; i < size; i++)
        {
            ans += distance[i];
        }
        return ans;
    }
};

int main()
{
    Graph p(7);         // for making directed use 2nd params as false
    p.addEdge(0, 1, 3); // v,u, & weight
    p.addEdge(1, 3, 3);
    p.addEdge(1, 5, 10);
    p.addEdge(2, 4, 6);
    p.addEdge(2, 6, 9);
    p.addEdge(3, 6, 8);
    p.addEdge(4, 5, 6);

    return 0;
};