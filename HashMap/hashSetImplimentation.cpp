#include <bits/stdc++.h>
using namespace std;
class MyHashSet
{
public:
    vector<vector<int>> bucket;
    int bucketSize = 209;

    MyHashSet()
    {
        vector<vector<int>> b(209, vector<int>());
        bucket = b;
    }

    void add(int key)
    {
        int index = key % bucketSize;
        if (!contains(key)) bucket[index].push_back(key);
    }

    void remove(int key)
    {
        int index = key % bucketSize;
        for (int i = 0; i < bucket[index].size(); i++)
        {
            if (bucket[index][i] == key)  bucket[index].erase(bucket[index].begin() + i);
        }
    }

    bool contains(int key)
    {
        int index = key % bucketSize;
        for (int i = 0; i < bucket[index].size(); i++)
        {
            if (bucket[index][i] == key)  return true;
        }
        return false;
    }
};

int main()
{
    MyHashSet p;
    p.add(345);
    p.add(9445);
    p.add(65345);
    p.add(33545);
    p.add(1545);
    p.remove(1545);
    cout << p.contains(9445);
    return 0;
}