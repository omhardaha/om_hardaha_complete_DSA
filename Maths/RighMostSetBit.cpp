#include <bits/stdc++.h>
using namespace std;

int main()
{
    //  final formula for right most set bit is
    int n = 10;
    int RMSB = n & (~n + 1); // = 2
    //   or
    RMSB = n & (-n); // = 2
    // cout << RMSB;
    bitset<16> d(-n);
    cout << d;
    // for further explanation
    // n = 10    //...00000001010
    //-n = -10   //...11111111010
    //                          &
    //                00000000010 = 2

    int x = 6;       //...000000001010
    int x1 = ~x;     //...111111110101  1s Compliment
    int x2 = ~x + 1; //...111111110110 =...111111110101 + 1 2s Compliment

    int RSB = x & x2;
    // ...111111110101
    // ...111111110110
    //               &
    //-----------------------
    //...0000000000010 this ia the right most bit 😃

    return 0;
}