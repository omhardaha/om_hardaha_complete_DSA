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
        l = vector<vector<int>>(size);
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
    void targenDfs(vector<vector<int>> &component, int &timer, vector<bool> &visited, vector<int> &low, vector<int> &distance, stack<int> &st, vector<bool> &inStack, int source)
    {
        st.push(source);
        visited[source] = inStack[source] = true;
        low[source] = distance[source] = timer++;
        for (auto i : l[source])
        {
            if (visited[i])
            {
                if (inStack[i])
                    low[source] = min(low[source], distance[i]); // upword node / downword node
            }
            else
            {
                targenDfs(component, timer, visited, low, distance, st, inStack, i);
                low[source] = min(low[source], low[i]); // upword node / downword node
            }
        }
        if (low[source] == distance[source]) // head node
        {
            vector<int> a;
            while (st.top() != source)
            {
                a.push_back(st.top());
                inStack[st.top()] = false;
                st.pop();
            }
            a.push_back(st.top());
            inStack[st.top()] = false;
            st.pop();
            component.push_back(a);
        }
    }
    vector<vector<int>> Tarjans()
    {
        vector<vector<int>> component;
        int timer = 0;
        vector<bool> visited(size, false);
        vector<bool> inStack(size, false);
        vector<int> low(size, -1);
        vector<int> distance(size, -1);
        stack<int> st;
        for (int i = 0; i < size; i++)
        {
            if (!visited[i])
            {
                targenDfs(component, timer, visited, low, distance, st, inStack, i);
            }
        }
        return component;
    }
};

int main()
{
    Graph p(7, false); // for making directed use 2nd params as false
    p.addEdge(0, 1);
    p.addEdge(1, 2);
    p.addEdge(1, 3);
    p.addEdge(4, 0);
    p.addEdge(3, 4);
    p.addEdge(4, 5);
    p.addEdge(4, 6);
    p.addEdge(5, 6);
    p.addEdge(5, 2);
    p.addEdge(6, 5);
    vector<vector<int>> component = p.Tarjans();
    cout << "f";
    for (auto row : component)
    {
        for (auto i : row)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
};