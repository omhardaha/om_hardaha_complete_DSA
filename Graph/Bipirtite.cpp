#include <bits/stdc++.h>
using namespace std;
bool isBipartiteHelper(vector<int> adj[], vector<int> &color, int source, int c, int perent)
{
    color[source] = c;
    for (auto i : adj[source])
    {
        if (i != perent)
        {
            if (color[i] != -1)
            {
                if (color[i] == c)
                    return false;
            }
            else
            {
                if (isBipartiteHelper(adj, color, i, (c == 0) ? 1 : 0, source) == false)
                    return false;
            }
        }
    }
    return true;
}
bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
            if (!isBipartiteHelper(adj, color, i, 0, -1))
                return false;
        ;
    }
    return true;
}
int main()
{

    return 0;
}