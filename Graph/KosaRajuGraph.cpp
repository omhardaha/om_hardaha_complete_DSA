#include <bits/stdc++.h>
using namespace std;
int size = 0;
stack<int> st;
vector<vector<int>> component;

void stackDfs(vector<int> l[], vector<bool> &visited, int source)
{
    visited[source] = true;
    for (auto i : l[source])
    {
        if (!visited[i])
        {
            stackDfs(l, visited, i);
        };
    }
    st.push(source);
}
void dfs(int source, vector<bool> &visited2, vector<int> &a, vector<vector<int>> &l)
{
    visited2[source] = true;
    a.push_back(source);
    for (auto &k : l[source])
    {
        if (!visited2[k])
        {
            dfs(k, visited2, a, l);
        }
    }
}
int kosaraju(int V, vector<int> l[])
{
    size = V;
    vector<bool> visited(size, false);
    vector<bool> visited2(size, false);
    for (int i = 0; i < size; i++)
    {
        if (!visited[i])
        {
            stackDfs(l, visited, i);
        }
    }
    vector<vector<int>> graph(V);
    for (int i = 0; i < V; i++)
    {
        for (auto p : l[i])
        {
            graph[p].push_back(i);
        }
    }
    while (!st.empty())
    {
        int r = st.top();
        st.pop();
        if (!visited2[r])
        {
            vector<int> a;
            dfs(r, visited2, a, graph);
            component.push_back(a);
        }
    }
    return component.size();
}
int main()
{

    return 0;
}