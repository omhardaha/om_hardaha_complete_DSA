#include <bits/stdc++.h>
using namespace std;

bool backspaceCompare(string s, string t)
{

    for (int i = 0; i < s.size(); i++)
    {
        if (i > 0 && s[i] == '#')
        {
            int temp = i - 1; 
            while (temp >= 0 && s[temp] == '#')
            {
                temp--;
            }
            if (s[temp] >= 0)
            {
                s[temp] = '#';
            }
        }
    }
    for (int i = 0; i < t.size(); i++)
    {
        if (i > 0 && t[i] == '#')
            t[i - 1] = '#';
    }
    int i = 0, j = 0;
    while (i < s.size() && j < t.size())
    {
        while (i < s.size() && s[i] == '#')
            i++;
        while (j < t.size() && t[j] == '#')
            j++;

        if (i < s.size() && j < t.size())
        {

            cout << "om" << endl;
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else
                return false;
        }
    }

    return i == s.size() && j == t.size();
}

int main()
{
    string s = "ab#c";
    string t = "ad#c";
    cout << backspaceCompare(s, t);
    return 0;
}