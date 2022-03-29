#include <bits/stdc++.h>
using namespace std;
string addString(string s1, string s2)
{
    if (s1.size() < s2.size())
    {
        swap(s1, s2);
    }
    int carry = 0;
    int i = s1.size() - 1;
    for (int j = s2.size() - 1; j >= 0; j--)
    {
        int u = (s1[i] - '0') + (s2[j] - '0') + carry;
        int val = u % 10;
        s1[i] = val + '0';
        carry = u / 10;
        i--;
    }
    if (carry > 0)
    {

        if (i < 0)
        {
            char c = carry + '0';
            s1 = c + s1;
        }
        else
        {
            for (int j = i; j >= 0; j--)
            {
                int val = (s1[j] - '0') + carry;
                int f = val % 10;
                s1[j] = f + '0';
                carry = val / 10;
            }
            if (carry > 0)
            {
                char c = carry + '0';
                s1 = c + s1;
            }
        }
    }
    return s1;
}
int main()
{

    return 0;
}