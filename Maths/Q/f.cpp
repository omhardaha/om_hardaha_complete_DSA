#include <bits/stdc++.h>
using namespace std;
int FindNonRepeatingNumInArray(vector<int> s)
{
    int k = s[0];
    for (int i = 1; i < s.size(); i++)
        k ^= s[i];
    return k;
    // {1, 2, 3, 4, 5, 1, 3, 4, 5} ans = 2
    // 1^2^3^4^5^1^3^4^5 = 2
    // bcoz 1^1 = 0 ;
    // bcoz 2^0 = 2 ;
    // bcoz 3^3 = 0 ;
    // bcoz 4^4 = 0 ;
    // bcoz 5^5 = 0 ;
}
int main(){
   
 return 0;
}