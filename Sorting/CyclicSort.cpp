#include <bits/stdc++.h>
using namespace std;
// 1 to N CyclicSort
void cyclicSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= arr.size())
        {
            while (arr[arr[i] - 1] != arr[i])
            {
                swap(arr[arr[i] - 1], arr[i]);
            }
        }
    }
}
// 0 to N-1 Cyclic Sort
void cyclicSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < arr.size())
        {
            while (arr[arr[i]] != arr[i])
            {
                swap(arr[arr[i]], arr[i]);
            }
        }
    }
}
int main()
{
    vector<int> arr = {2, 3, 4, 6, 1, 5, 8};
    cyclicSort(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}