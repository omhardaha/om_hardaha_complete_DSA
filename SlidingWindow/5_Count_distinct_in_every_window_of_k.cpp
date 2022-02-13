#include <bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1/
vector<int> countDistinct(vector<int> A, int k)
{
    vector<int> ans;
    unordered_map<int, int> p;

    for (int i = 0; i < A.size(); i++)
    {
        p[A[i]]++;

        if (i >= k - 1)
        {
            ans.push_back(p.size());

            if (p[A[i - k + 1]] == 1)
                p.erase(A[i - k + 1]);
            else
                p[A[i - k + 1]]--;
        }
    }
    return ans;
}
int main()
{
vector<int> t = {1, -1, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = countDistinct(t, k);

    for (auto i : t)
        cout << i << " ";
    cout << endl;

    for (auto i : ans)
        cout << i << " ";
    return 0;
}