#include <bits/stdc++.h>
using namespace std;

class Graph
{
private:
    int size;
    vector<int> *l;

public:
    Graph(int v)
    {
        size = v;
        l = new vector<int>[v];
    }

    void addEdge(int m, int n, bool dir = false)
    {
        l[m].push_back(n);
        if (!dir)
            l[n].push_back(m);
    }

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

    bool bfsCycleHelper(int source, vector<bool> &visited)
    {
        queue<pair<int, int>> nodes;
        nodes.push({source, -1});
        visited[source] = true;

        while (!nodes.empty())
        {
            int cur = nodes.front().first;
            int prev = nodes.front().second;
            nodes.pop();
            for (auto i : l[cur])
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    nodes.push({i, cur});
                }
            }
        }

        return false;
    }
    bool bfsCycle()
    {
        vector<bool> visited(size, false);
        for (int i = 0; i < size; i++)
        {
            if (!visited[i])
            {
                if (bfsCycleHelper(i, visited))
                {
                    return true;
                };
            }
        }
        return false;
    }
};

int main()
{
    Graph p(7);
    p.addEdge(1, 2);
    p.addEdge(2, 3);
    p.addEdge(4, 3);
    p.addEdge(1, 4);
    // p.printGraph();
    // p.dfs(1);

    return 0;
};