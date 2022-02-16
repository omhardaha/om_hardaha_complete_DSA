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

  void addEdge(int m, int n)
  {
    l[m].push_back(n);
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
};

int main()
{
  Graph p(7);
  p.addEdge(1, 2);
  p.addEdge(1, 5);
  p.addEdge(2, 6);
  p.addEdge(2, 1);
  p.addEdge(6, 2);
  p.addEdge(6, 5);
  p.addEdge(5, 1);
  p.addEdge(5, 6);
  p.addEdge(5, 0);
  p.addEdge(5, 4);
  // p.printGraph();
  p.bfs(1);
  return 0;
}