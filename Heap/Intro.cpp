#include <bits/stdc++.h>
using namespace std;
// ----Heap-----
// Parent(i) = i / 2;
// left Child (i) = i * 2
// Right Child (i) = ( i * 2 )+ 1

class Heap
{
public:
    vector<int> data = {50, 30, 40, 10, 5, 20, 10, 60};
    int size = 8;
    void insert(int n)
    {
        size++;
        data.push_back(n);
    }
};

int main()
{
    Heap k;
    k.insert(5);
    k.insert(5);
    k.insert(2);

    for (auto i : k.data)
        cout << i << endl;
    return 0;
}