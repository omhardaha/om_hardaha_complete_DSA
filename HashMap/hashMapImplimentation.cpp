#include <bits/stdc++.h>
using namespace std;
class MyHashMap
{
public:
    vector<vector<pair<int, int>>> bucket;
    int bucketSize = 200;
    MyHashMap()
    {
        vector<vector<pair<int, int>>> temp(bucketSize, vector<pair<int, int>>());
        bucket = temp;
    }

    void put(int key, int value)
    {
        int index = key % bucketSize;
        if (get(key) == -1) bucket[index].push_back({key, value});
        else
        {
            for (int i = 0; i < bucket[index].size(); i++)
            {
                if (bucket[index][i].first == key)
                {
                    bucket[index][i].second = value;
                    return;
                }
            }
        }
    }

    int get(int key)
    {
        int index = key % bucketSize;
        for (int i = 0; i < bucket[index].size(); i++)
        {
            if (bucket[index][i].first == key) return bucket[index][i].second;
        }
        return -1;
    }

    void remove(int key)
    {
        int index = key % bucketSize;
        for (int i = 0; i < bucket[index].size(); i++)
        {
            if (bucket[index][i].first == key)
            {
                bucket[index].erase(bucket[index].begin() + i);
                return;
            }
        }
    }
};

int main()
{
    MyHashMap p;
    p.put(6, 8);
    p.put(9445, 8);
    p.put(65345, 84);
    p.put(33545, 555);
    p.put(1545, 8);
    p.remove(1545);
    cout << p.get(6);
    return 0;
}