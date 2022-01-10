#include <bits/stdc++.h>
using namespace std;

bool isODD(int n)
{

    return (n & 1) == 1;

    //  Example 7 & 1
    //   0111 (7)
    // & 0001 (1)
    // ans = 0001 (5) this give the last digit

    //  Example 8 & 1
    //   1000 (7)
    // & 0001 (1)
    // ans = 0000 (0)
}

int FindNonRepeatingNumInArray(vector<int> s)
{
    int k = s[0];
    for (int i = 1; i < s.size(); i++) k ^= s[i]; 
    return k;
    // {1, 2, 3, 4, 5, 1, 3, 4, 5} ans = 2
    // 1^2^3^4^5^1^3^4^5 = 2
     // bcoz 1^1 = 0 ;
     // bcoz 2^0 = 2 ;
     // bcoz 3^3 = 0 ;
     // bcoz 4^4 = 0 ;
     // bcoz 5^5 = 0 ;
}

int FindIthBIT(int n, int ith){

    int bitIth = (1<<(ith-1));

return (n& bitIth) == bitIth ;

// if n = 27
//  11011 (27)
//  for finding 3rd bit 
//     11011
//   & 00100
//   ---------
//     00000   == 1<<(3-1) then ans = 1 else 0
//  for finding 2rd bit 
//     11011
//   & 00010
//   ---------
//     00010  == 1<<(2-1) then ans = 1 else 0
}

int SetIthBIT(int n, int ith){

    int bitIth = (1<<(ith-1));

return (n | bitIth) ;

// if n = 27
//  11011 (27)

//  set  3rd bit 
//        11011
// | (or) 00100 (ith bit)
//   ---------------------
//        11111   = ans

//  set  2nd bit 
//        11011
// | (or) 00010 (ith bit)
//   ---------------------
//        11011   = ans
}

int ResetIthBIT(int n, int ith){

    int bitIth = ~(1<<(ith-1));
return (n & bitIth) ;

// if n = 27
//  11011 (27)

//  reset  3rd bit 
//         11011
// & (and) 11011 (ith bit)
//   ---------------------
//        11011   = ans

//  reset  2nd bit 
//         11011
// & (and) 11101 (ith bit)
//   ---------------------
//         11001   = ans
}

int main()
{
    //      ------XOR------
    // (both same = 0 )
    // cout<< (3 ^ 6) ;
    //  Example  -
    //       0011 (3)
    //     ^ 0110 (6)
    // ans = 0101 (5)
    // IMP ✔
    // a ^ 1 = compliment of a
    // a ^ 0 = a
    // a ^ a = 0

    //      ------ <<  (Left Shift)------
    // cout<< (6<<1) ;
    //  Example -
    //       0110 (6)   <<  1 =
    //      01100 (12)
    //  Shift All digit left and add 0 in last
    // a<<b = a  * 2 ^ b
    // 3<<4 = 3  * 2 ^ 4

    //      ------ >>  (Right Shift)------
    // cout<< (6>>1) ;
    //  Example -
    //       0110 (6)   >>  1 =
    //       0011 (3)
    //  Shift All digit Right and add 0 in start
    // a<<b = a  / 2 ^ b
    // 60<<4 = 3  / 2 ^ 4 = 3

    //      ------Non-Repeating-Int------
    // vector<int> s = {1, 2, 3, 4, 5, 1, 3, 4, 5};
    // cout << FindNonRepeatingNumInArray(s);

    //      ------Find ith Bit------
    // cout << FindIthBIT(27,3);

    //      ------Set ith Bit 1------
    // cout << SetIthBIT(27,1);

    //      ------Reset ith Bit 1------
    // cout << ResetIthBIT(27,1);

    return 0;
}