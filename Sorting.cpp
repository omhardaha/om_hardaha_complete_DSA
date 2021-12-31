#include <bits/stdc++.h>
using namespace std;

void cycleSort(vector<int> &arr)//1 to N element
{
    for (int i = 0; i < arr.size(); i++)
        while (arr[i] != i + 1)
            swap(arr[i], arr[arr[i] - 1]);
};
//another method
void cycleSort2(vector<int> &arr)//1 to N element
{
    int i=0;
   while (i<arr.size())
   {
      int correctIndex = arr[i]-1;

      if(arr[i] != arr[correctIndex]) 
            swap(arr[i],arr[correctIndex]);

      else i++;   
   }
   
};

int missingNumber(vector<int> &arr)//1 to N element
{
    for (int i = 0; i < arr.size(); i++)
        while (arr[i] != i && arr[i]<arr.size()-1)
            swap(arr[i], arr[arr[i] ]);
    //  int i = 0
    for (int i=0; i < arr.size(); i++)
       if(arr[i]!=i)return i;
   
   return arr.size();
};

int main()
{
    vector<int> arr{3, 5, 2, 1, 4};
    // vector<int> arr{3, 0,1};
    for (auto i : arr)
     cout << i << " ";

    cycleSort2(arr);
    // cout<<missingNumber(arr);
    for (auto i : arr)
        cout << i << " ";
    return 0;
}