#include <bits/stdc++.h>
using namespace std;

bool comp(string a, string b)
{
    if (a[0] == b[0])
    {
        // return a.size() <= b.size();
        if (a.size() == b.size())
        {
            return a <= b;
        }
        else if (a.size() < b.size())
        {
            
        }
        else
        {

        }
    }
    if (a[0] > b[0])
    {
        return false;
    }
    return true;
}
int main()
{
    vector<string> number = {"3", "30", "34", "5", "9"};
    sort(number.begin(), number.end(), comp);
    for (auto i : number)
        cout << i << " ";
    return 0;
}