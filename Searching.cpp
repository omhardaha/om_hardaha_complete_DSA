#include <bits/stdc++.h>
using namespace std;
// question sloved of leetcode-
// https://github.com/kunal-kushwaha/DSA-Bootcamp-Java/blob/main/assignments/06-searching.md

int linearSearch(int a[], int n, int val)
{
  for (int i = 0; i < n; i++)
    if (a[i] == val)
      return i;

  return -1;//if val not found
};
int binarySearch(int a[], int l,int h, int val)
{
  // int low =l;
  // int high =h;
  int mid =l+(h-l)/2;

  
  return -1;//if val not found
};

int main()
{
  int arr[] = {2, 4356, 46, 4643, 634, 5};
  cout << linearSearch(arr, 6, 646);
  return 0;
}