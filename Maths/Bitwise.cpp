#include <bits/stdc++.h>
using namespace std;



int FindNonRepeatingNumInArrayMoreThan2Number(vector<int> s)
{
    int bits[32] = {0};
    int bitsofMinus[32] = {0};
    int base;
    int ans = 0;
    for (auto num : s)
    {
        base = 0;
        while (num > 0)
        {
            if (num & 1)
                bits[base]++;
            num = num >> 1;
            base++;
        }
        num = abs(num);
        while (num > 0)
        {
            if (num & 1)
                bitsofMinus[base]++;
            num = num >> 1;
            base++;
        }
    }

    for (int i = 0; i < 32; i++)
    {
        ans += (bits[i] % 3) * pow(2, i);
    };

    if (ans == 0)
    {

        for (int i = 0; i < 32; i++)
        {
            ans += (bitsofMinus[i] % 3) * pow(2, i);
        };
        ans = -ans;
    }
    return ans;
}

int FindIthBIT(int n, int ith)
{

    int bitIth = (1 << (ith - 1));

    return (n & bitIth) == bitIth;

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

int SetIthBIT(int n, int ith)
{

    int bitIth = (1 << (ith - 1));

    return (n | bitIth);

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

int ResetIthBIT(int n, int ith)
{
    int bitIth = ~(1 << (ith - 1));
    return (n & bitIth);

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

    //      ------Non-Repeating-Int-2>------
    // vector<int> s = {-2,-2,1,1,4,1,4,4,-4,-2};
    // cout << FindNonRepeatingNumInArrayMoreThan2Number(s);

    //      ------Find ith Bit------
    // cout << FindIthBIT(27,3);

    //      ------Set ith Bit 1------
    // cout << SetIthBIT(27,1);

    //      ------Reset ith Bit 1------
    // cout << ResetIthBIT(27,1);

    //      ------Compliment Of a Number------
    // cout << (~27) +1;

    //  ------Compliment Of a Number------
    // cout << (1^2^1^3^2^5) ;

    //  ------Find No of digit in base b------
    // 10 have 4 digit
    // 7 hv 3
    // 64 hv 5
    // int numberOfDigit = log2(10) +1;
    // cout << numberOfDigit ;
    int n = 46;
    string s = to_string(n);
    sort(s.rbegin(), s.rend());
    n = stoi(s);
    cout << n;

    return 0;
}