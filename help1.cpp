#include <bits/stdc++.h>
using namespace std;

int main()
{
    ATM j;
    j.deposit(vector<int>{0, 10, 0, 3, 0});
    vector<int> l = j.withdraw(500);
    cout << endl;
    for (auto i : l)
        cout << i << " ";
    // j.deposit(vector<int>{0, 1, 0, 1, 1});

    // l = j.withdraw(600);
    // cout << endl;
    // for (auto i : l)
    //     cout << i << " ";

    // l = j.withdraw(550);

    // cout << endl;
    // for (auto i : l)
    //     cout << i << " ";
    return 0;
}