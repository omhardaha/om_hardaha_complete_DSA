#include <bits/stdc++.h>
using namespace std;
// question sloved of leetcode- https://github.com/kunal-kushwaha/DSA-Bootcamp-Java/blob/main/assignments/06-searching.md

int linearSearch(int a[], int n, int val)
{
  for (int i = 0; i <= n; i++)
    if (a[i] == val)
      return i;

  return -1;//if val not found
};

int binarySearch(int a[],int h, int val)
{
  int low = 0;
  int high = h-1;

 while (low<=high)
 {
  int mid = low+(high-low)/2;
  if (a[mid] == val) return mid;
  else if(val>a[mid]) low =mid+1;
  else high =mid-1;
 }

  return -1;//if val not found
};
int binarySearchInfiniteArray(int a[], int val)
{
  int low = 0;
  int high = 1;

 while (low<=high)
 {
   if(val>a[high]){
     low = high+1;
     high *=2;
   }

  int mid = low+(high-low)/2;

  if (a[mid] == val) return mid;

  else if(val>a[mid]) low =mid+1;

  else high =mid-1;

 }
  return -1;//if val not found
};

int ceilingNumber(int a[],int h, int val)
{
  if(a[h-1] < val) return -1; // bcz no ceiling present
  int low = 0;
  int high = h-1;

 while (low<=high)
 {
  int mid = low+(high-low)/2;
  if (a[mid] == val) return mid;
  else if(val>a[mid]) low =mid+1;
  else high =mid-1;
 }

  return low;//if val not found
};
int floorNumberv(int a[],int h, int val)
{
  int low = 0;
  int high = h-1;

 while (low<=high)
 {
  int mid = low+(high-low)/2;
  if (a[mid] == val) return mid;
  else if(val>a[mid]) low =mid+1;
  else high =mid-1;
 }

  return high;//if val not found
};

int main()
{
  // int arr[] = {2,3,6,8,9,19};
  int arr[] = {2,3,6,8,9,19,444,6666,8888,22222,6234544};//11

  // cout << binarySearch(arr,6, 10);
  // cout << ceilingNumber(arr,6, 29);
  // cout << floorNumberv(arr,6, 1);
  cout << binarySearchInfiniteArray(arr, 444);
  return 0;
}