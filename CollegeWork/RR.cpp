#include <bits/stdc++.h>
using namespace std;
int main()
{
    int TotalWT = 0, TotalBT = 0, n, t = 1;
    cout << "Enter Number Of Process - ";
    cin >> n;
    cout << "Enter Time Quantum - ";
    cin >> t;
    vector<int> BT(n), TempBT(n), WT(n, 0), TAT(n);
    cout << "Enter Burst Time Of processes -" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> BT[i];
        TempBT[i] = BT[i];
        TotalBT += BT[i];
    }
    int Round = 0;
    while (TotalBT)
    {
        for (int i = 0; i < n; i++)
        {
            if (TempBT[i] > 0)
            {
                if (TempBT[i] > t)
                {
                    Round += t;
                    TempBT[i] -= t;
                    TotalBT -= t;
                }
                else
                {
                    Round += TempBT[i];
                    TotalBT -= TempBT[i];
                    WT[i] = Round - BT[i];
                    TempBT[i] = 0;
                }
            }
        }
    }
    cout << endl
         << "No  BT  WT  TAT" << endl;
    for (int i = 0; i < n; i++)
    {
        TotalWT += WT[i];
        TAT[i] = BT[i] + WT[i];
        cout << i + 1 << "   " << BT[i] << "   " << WT[i] << "   " << TAT[i] << endl;
    }

    cout << "Average Waiting Time is - " << (float)TotalWT / (float)n;
    return 0;
}