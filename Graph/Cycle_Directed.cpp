#include <bits/stdc++.h>
using namespace std;
bool cycle(vector<int> adj[], vector<bool> &visited, vector<bool> &inStack, int s)
{
    visited[s] = true;
    inStack[s] = true;
    for (auto &i : adj[s])
    {
        if (inStack[i])
            return true;
        if (!visited[i] && cycle(adj, visited, inStack, i))
            return true;
    }
    inStack[s] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    vector<bool> visited(V);
    vector<bool> inStack(V);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            if (cycle(adj, visited, inStack, i))
                return true;
    }
    return false;
}
int main()
{

    return 0;
}