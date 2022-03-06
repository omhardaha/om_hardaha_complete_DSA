#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vpii vector<pair<int, int>>
#define vvi vector<vector<int>>

class DisJointSet
{
public:
    vector<int> perent;
    vector<int> rank;
    DisJointSet(int size)
    {
        perent = vector<int>(size);
        for (int i = 0; i < size; i++)
        {
            perent[i] = i;
        }
        rank = vector<int>(size, 1);
    };

    void makeUnion(int u, int v)
    {
        int p1 = findPerent(u);
        int p2 = findPerent(v);

        if (rank[p1] < rank[p2])
        {
            perent[p1] = p2;
        }
        else if (rank[p1] > rank[p2])
        {
            perent[p2] = p1;
        }
        else
        {
            perent[p1] = p2;
            rank[p2]++;
        }
    };
    int findPerent(int x)
    {
        if (x == perent[x])
        {
            return x;
        }
        return perent[x] = findPerent(perent[x]);
    };
};

int main()
{
    // given edges
    vector<vector<int>> edges;
    edges.push_back({0, 1, 4}); // v,u, & weight
    edges.push_back({1, 3, 2});
    edges.push_back({1, 2, 1});
    edges.push_back({2, 0, 3});
    edges.push_back({2, 3, 4});
    edges.push_back({3, 4, 2});
    edges.push_back({4, 5, 6});

    // putting all edges in kust and sort by W
    vector<vector<int>> kusk;
    for (auto p : edges)
    {
        kusk.push_back({p[2], p[0], p[1]});
    }
    sort(kusk.begin(), kusk.end());


    DisJointSet D(6);
    int i = 0;
    int NEdges = 5;
    int minE = 0;
    // run the loop till N-1 edges and check whether two nodes are same perent or not
    while (NEdges)
    {
        cout<<"w"<<endl;
        if (D.perent[kusk[i][1]] != D.perent[kusk[i][2]])
        {
        cout<<"w5"<<endl;
            D.makeUnion(kusk[i][1], kusk[i][2]);
            minE += kusk[i][0];
            NEdges--;
        }
        i++;
    }

    cout<<minE;
    return 0;
}