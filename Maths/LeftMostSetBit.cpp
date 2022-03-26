#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 1;
    int LMSB = 1 << ((int)log(n) + 1); // = 8
    cout << LMSB;
    return 0;
}