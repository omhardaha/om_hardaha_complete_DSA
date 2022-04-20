#include <bits/stdc++.h>
using namespace std;
int main()
{
    int TotalWT = 0, n;
    cout << "Enter Number Of Process - ";
    cin >> n;
    vector<int> BT(n), WT(n,0), TAT(n);
    cout << "Enter Burst Time Of processes -" << endl;

    for (int i = 0; i < n; i++)  cin >> BT[i];

    // sort(BT.begin(), BT.end());
    cout << "No.  BT  WT  TAT" << endl;
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            WT[i] = WT[i - 1] + BT[i - 1];
        TotalWT += WT[i];
        TAT[i] = BT[i] + WT[i];
        cout << i + 1 << "   " << BT[i] << "   " << WT[i] << "   " << TAT[i] << endl;
    }
    cout << "Average Waiting Time is -" << (float)TotalWT / (float)n;
    return 0;
}