#include <bits/stdc++.h>
using namespace std;

class Item
{
public:
    int priority, BT, ID;
};

bool comp(Item a, Item b)
{
    return (a.priority > b.priority);
}

int main()
{
    int TotalWT = 0, n;
    cout << "Enter Number Of Process - ";
    cin >> n;
    vector<Item> BT(n);
    vector<int> WT(n, 0), TAT(n);
    cout << "Enter Priority & Burst Time Of processes -" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "ID - " << i + 1 << " " << endl<< "P - ";
        cin >> BT[i].priority;
        cout << "BT - ";
        cin >> BT[i].BT;
        cout << endl;
        BT[i].ID = i + 1;
    }

    sort(BT.begin(), BT.end(), comp);

    cout << "No  P  BT  WT  TAT" << endl;

    for (int i = 0; i < n; i++)
    {
        if (i > 0)  WT[i] = WT[i - 1] + BT[i - 1].BT;
        TotalWT += WT[i];
        TAT[i] = BT[i].BT + WT[i];
        cout << BT[i].ID << "   " << BT[i].priority << "   " << BT[i].BT << "   " << WT[i] << "   " << TAT[i] << "   " << endl;
    }
    cout << "Average Waiting Time is - " << (float)TotalWT / (float)n;
    return 0;
}