#include <bits/stdc++.h>
using namespace std;
vector<int> arr(4);
bool check(int a, int b)
{
    bool flag = true;
    if ((a + b) != arr[0] && (a + b) != arr[1] && (a + b) != arr[2] && (a + b) != arr[3])
    {
        flag = false;
    }
    if ((a - b) != arr[0] && (a - b) != arr[1] && (a - b) != arr[2] && (a - b) != arr[3])
    {
        flag = false;
    }
    if ((a * b) != arr[0] && (a * b) != arr[1] && (a * b) != arr[2] && (a * b) != arr[3])
    {
        flag = false;
    }
    if ((a / b) != arr[0] && (a / b) != arr[1] && (a / b) != arr[2] && (a / b) != arr[3])
    {
        flag = false;
    }
    return flag;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ansa = -1;
        int ansb = -1;
        cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
        bool flag = false;
        for (int i = 0; i <= 3; i++)
        {
            // cout << "rrrrr" << endl;
            for (int k = 0; k <= 3; k++)
            {
                // cout << "yyyy" << endl;
                if (k != i)
                {
                    int a = (arr[i] + arr[k]) / 2;
                    int b = arr[i] - a;
                    // cout << a << endl;
                    // cout << b << endl;
                    if (check(a, b))
                    {
                        ansa = a;
                        ansb = b;
                        flag = true;
                    };
                }
            }
        }
        if (flag)
        {
            cout << ansa << " " << ansb << endl;
        }
        else
        {
            cout << -1 << " " << -1 << endl;
        }
    }
    return 0;
}
