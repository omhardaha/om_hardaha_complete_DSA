#include <bits/stdc++.h>
using namespace std;
// Algorithm
//  1. find index (Fi) that arr[Fi] < arr[Fi] from back to start of array.
//  2. Search for index Hi that arr[Hi] > arr[Fi].
//  3. Swap (arr[Hi] > arr[Fi]).
//  4. Reverse Array from Fi+1 to End of Array
// 5. In Case we can not find Fi that means it is a Sorted Array(decreasing) We have simply reverse Array
void nextPermutation(vector<int> &arr)
{
    int firstIndex = INT_MAX;
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            firstIndex = i;
            break;
        }
    }
    if (firstIndex == INT_MAX)
    {
        reverse(arr.begin(), arr.end());
    }
    else
    {
        int highIndex = INT_MAX;
        for (int i = arr.size() - 1; i >= 0; i--)
        {
            if (arr[i] > arr[firstIndex])
            {
                highIndex = i;
                break;
            }
        }
        swap(arr[highIndex], arr[firstIndex]);
        reverse(arr.begin() + firstIndex + 1, arr.end());
    }
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    nextPermutation(arr);
    nextPermutation(arr);
    nextPermutation(arr);
    nextPermutation(arr);
    nextPermutation(arr);
    nextPermutation(arr);
    nextPermutation(arr);
    nextPermutation(arr);
    nextPermutation(arr);
    nextPermutation(arr);
    nextPermutation(arr);
    nextPermutation(arr);
    nextPermutation(arr);
    return 0;
}