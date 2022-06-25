#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int size;
    bool unDirected;
    vector<vector<int>> l;

public:
    // Graph Constructor
    //  Note - Use second argument as false if use want to create directed graph
    Graph(int v, bool dir = true)
    {
        size = v;
        unDirected = dir;
        l = vector< vector<int> >(size);
    }

    // adding edge
    void addEdge(int m, int n)
    {
        l[m].push_back(n);
        if (unDirected)
        {
            l[n].push_back(m);
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
                cout << i << " ";
            }
            cout << endl;
        }
    }

    //                🧨🧨🧨Travesals🧨🧨🧨
    //  Breadth First Search (BFS)
    void bfs(int source)
    {
        cout << "bfs is --> ";
        queue<int> q;
        vector<bool> visited(size);

        q.push(source);
        visited[source] = true;

        while (!q.empty())
        {
            int d = q.front();
            cout << d << " ";
            q.pop();

            for (auto i : l[d])
            {
                if (!visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    // Depth First Search (DFS)
    void dfshelper(int source, vector<bool> &visited)
    {
        visited[source] = true;
        cout << source << " ";
        for (auto i : l[source])
        {
            if (!visited[i])
            {
                dfshelper(i, visited);
            }
        }
    }
    void dfs(int source)
    {
        cout << "dfs is --> ";
        vector<bool> visited(size, false);
        dfshelper(source, visited);
    }

    //               🧨🧨🧨Cylce Detection🧨🧨🧨
    // Cylce Detection Using bfs
    bool bfsCycle()
    {
        vector<bool> visited(size, false);
        for (int i = 0; i < size; i++)
        {
            if (!visited[i])
            {
                queue<pair<int, int>> nodes;
                nodes.push({i, -1});
                visited[i] = true;
                while (!nodes.empty())
                {
                    int cur = nodes.front().first;
                    int prev = nodes.front().second;
                    nodes.pop();
                    for (auto node : l[cur])
                    {
                        if (visited[node] && node != prev)
                        {
                            return true;
                        }
                        if (!visited[node])
                        {
                            visited[node] = true;
                            nodes.push({node, cur});
                        }
                    }
                }
            }
        }
        return false;
    }

    // Cylce Detection Using dfs
    bool dfsCycleHelper(int source, vector<bool> &visited, int perent)
    {
        visited[source] = true;
        for (auto node : l[source])
        {
            if (visited[node] && node != perent)
            {
                return true;
            }
            if (!visited[node])
            {
                visited[node] = true;
                dfsCycleHelper(node, visited, source);
            }
        }
        return false;
    };
    bool dfsCycle()
    {
        vector<bool> visited(size, false);
        for (int i = 0; i < size; i++)
        {
            if (!visited[i])
            {
                if (dfsCycleHelper(i, visited, -1))
                {
                    return true;
                };
            }
        }
        return false;
    };

    // Cylce Detection Using dfs in DirectedGraph
    bool dfsCycleDirectedGraphHelper(int source, vector<bool> &visited, vector<bool> &dfsVisited)
    {
        visited[source] = true;
        dfsVisited[source] = true;
        for (auto i : l[source])
        {
            if (!visited[i])
            {
                if (dfsCycleDirectedGraphHelper(i, visited, dfsVisited))
                {
                    return true;
                };
            }
            else if (dfsVisited[i])
            {
                return true;
            }
        }
        dfsVisited[source] = false;

        return false;
    };
    bool dfsCycleDirectedGraph()
    {
        vector<bool> visited(size, false);
        vector<bool> dfsVisited(size, false);
        for (int i = 0; i < size; i++)
        {
            if (!visited[i])
            {
                if (dfsCycleDirectedGraphHelper(i, visited, dfsVisited))
                {
                    return true;
                };
            }
        }
        return false;
    }

    //                 🧨🧨🧨Bipartite Graph🧨🧨🧨
    // Checking Graph is Bipartite Graph or Not using bfs
    bool isBipartiteBFS(int source)
    {
        vector<int> colored(size, -1);
        colored[source] = 1;
        queue<int> q;
        q.push(source);

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();
            for (auto i : l[temp])
            {
                if (colored[i] == colored[temp])
                {
                    return false;
                }
                if (colored[i] == -1)
                {
                    colored[i] = !colored[temp];
                    q.push(i);
                }
            }
        }
        return true;
    }

    //                🧨🧨🧨 Topological Sort 🧨🧨🧨
    // Topological Sort Using DFS. Note - TopoLogical only present when Graph is DAG.
    void topologicalSortDfsHelper(int source, stack<int> &st, vector<bool> &visited)
    {
        visited[source] = true;
        for (auto i : l[source])
        {
            if (!visited[i])
            {
                topologicalSortDfsHelper(i, st, visited);
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

    // Topological Sort Using BFS (Kahn's Algorithm)
    vector<int> topologicalSortBfs()
    {
        //  ---Kahn's Algorithm---
        vector<int> inDegree(size, 0);
        vector<int> topoList;
        for (int i = 0; i < size; i++)
        {
            for (auto p : l[i])
            {
                inDegree[p]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < size; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            topoList.push_back(q.front());
            int node = q.front();
            q.pop();
            for (auto i : l[node])
            {
                inDegree[i]--;
                if (inDegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        return topoList;
    }
    bool bfsCycleDirectedGraph()
    {
        // we can also check bfsCycleDirectedGraph using Kanhs algo bcoz topologicalSortList not done in Kahn's Algorithm
        vector<int> inDegree(size, 0);
        for (int i = 0; i < size; i++)
        {
            for (auto p : l[i])
            {
                inDegree[p]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < size; i++)
        {
            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty())
        {
            count++;
            int node = q.front();
            q.pop();
            for (auto i : l[node])
            {
                inDegree[i]--;
                if (inDegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }
        return count == size;
    }

    ///             🧨🧨🧨 Shortest Path (Un-Weighted Weighted=1🐧)🧨🧨🧨
    // Shortest Path in Undirected Graph with Unit(1) Weights
    vector<int> shortestPath(int source)
    {
        vector<int> distance(size, INT_MAX);
        int length = 0;
        distance[source] = 0;
        queue<int> q;
        q.push(source);
        while (!q.empty())
        {
            int qsize = q.size();
            int node = q.front();
            q.pop();
            for (auto i : l[node])
            {
                if (distance[node] + 1 < distance[i])
                {
                    q.push(i);
                    distance[i] = distance[node] + 1;
                }
            }
        }

        return distance;
    }

    void dfsHelperBridges(vector<pair<int, int>> &bridgesEdges, vector<bool> &visited, vector<int> &low, vector<int> &insertTime, int i, int &count, int perent)
    {
        visited[i] = true;
        low[i] = insertTime[i] = ++count;
        for (auto node : l[i])
        {
            if (node == perent)
                continue;
            if (!visited[node])
            {
                dfsHelperBridges(bridgesEdges, visited, low, insertTime, node, count, i);
                low[i] = min(low[i], low[node]);
                if (low[node] > low[i])
                {
                    bridgesEdges.push_back({node, i});
                }
            }
            else
            {
                low[i] = min(low[i], insertTime[node]);
            }
        }
    }
    vector<pair<int, int>> bridges()
    {
        vector<pair<int, int>> bridgesEdges;
        vector<bool> visited(size, false);
        vector<int> low(size, INT_MAX);
        vector<int> insertTime(size, INT_MAX);
        int count = 0;
        dfsHelperBridges(bridgesEdges, visited, low, insertTime, 0, count, 0);
        return bridgesEdges;
    }
};

int main()
{
    Graph p(5); // for making directed use 2nd params as false
    p.addEdge(1, 2);
    p.addEdge(1, 0);
    p.addEdge(1, 3);
    p.addEdge(2, 0);
    p.addEdge(3, 4);
    // p.addEdge(0, 4);
    // p.addEdge(5, 4);
    // p.addEdge(5, 3);
    // p.addEdge(5, 6);
    // p.addEdge(4, 2);
    // p.addEdge(0, 1);

    // p.bfs(0);

    vector<pair<int, int>> brig = p.bridges();
    for (auto i : brig)
        cout << i.first << " " << i.second << endl;

    // cout << endl
    //      << p.shortestPath(5);
    return 0;
};