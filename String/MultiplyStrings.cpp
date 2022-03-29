#include <bits/stdc++.h>
using namespace std;
string multStrWithChar(string s, char n)
{
    if (n == '0')
    {
        return "0";
    }
    int carry = 0;
    int p = n - '0';
    for (int i = s.size() - 1; i >= 0; i--)
    {
        int u = s[i] - '0';
        u *= p;
        u += carry;

        int m = u % 10;
        carry = u / 10;
        s[i] = m + '0';
    }
    char c = ('0' + carry);

    if (c != '0')
    {
        s = c + s;
    }
    return s;
}

string addString(string s1, string s2)
{
    if (s1.size() < s2.size())
    {
        swap(s1, s2);
    }
    int carry = 0;
    int i = s1.size() - 1;
    // int j = s2.size() - 1;
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
            // cout<<carry<<endl;
            for (int j = i; j >= 0; j--)
            {
                int val = (s1[j] - '0') + carry;
                // cout<<s1[j]<<endl;
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
    string s = "2424";
    string d = "9777";
    string ans = "";
    int count = d.size() - 1;
    for (int i = 0; i < d.size(); i++)
    {
        string temp = multStrWithChar(s, d[i]);
        for (int m = 0; m < count; m++)
        {
            temp += '0';
        }
        count--;
        ans = addString(ans, temp);
    }
    cout << ans;
    return 0;
}