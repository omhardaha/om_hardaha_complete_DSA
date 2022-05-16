#include <bits/stdc++.h>
using namespace std;
class Graph
{
private:
    int size;
    int i = 10;
    bool unDirected;
    vector<vector<pair<int, int>>> l;

public:
    // Graph Constructor
    //  Note - Use second argument as false if use want to create directed graph
    Graph(int v, bool dir = true)
    {
        size = v;
        unDirected = dir;
        l = vector<vector<pair<int, int>>>(size);
    }

    // adding edge
    void addEdge(int v, int u, int weight)
    {
        // cout << "i -> " << u << " j -> " << v <<" w-> "<<weight<< endl;

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
    // Graph p(7, false); // for making directed use 2nd params as false

    // p.addEdge(0, 1, 3); // v,u, & weight
    // p.addEdge(1, 3, 3);
    // p.addEdge(1, 5, 10);
    // p.addEdge(2, 4, 6);
    // p.addEdge(2, 6, 9);
    // p.addEdge(3, 6, 8);
    // p.addEdge(4, 5, 6);

    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    Graph p(points.size(), false); // for making directed use 2nd params as false
    for (int u = 0; u < points.size(); u++)
    {
        for (int v = 0; v < points.size(); v++)
        {
            if (u != v)
            {
                p.addEdge(u, v, abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]));
            }
        }
    }

    p.printGraph();
    cout << p.PrimsAlgorithmMinSpanningTree();
    return 0;
};