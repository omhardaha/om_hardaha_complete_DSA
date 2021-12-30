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
int binarySearchRange(int a[],int l,int h, int val)
{
  int low = l;
  int high = h;

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
     int newlow = high+1;
     high = high + (high-low+1)*2;
     low = newlow;
   }
   else{
  int mid = low+(high-low)/2;

  if (a[mid] == val) return mid;
  else if(val>a[mid]) low =mid+1;
  else high =mid-1;

   }
 }

  return -1;//if val not found
};
int RotatedArrayPeek(int a[],int h)
{
  int low = 0;
  int high = h;
 while (low<high)
 {
   int mid = low + (high - low)/2;

if(mid<h+1 && a[mid]>a[mid+1])return mid; //ans
if(mid>0 && a[mid]<a[mid-1])return mid-1; //ans
     
if(a[low]<a[mid])low=mid+1;
else if(a[low]>=a[mid])high=mid-1;
 };

  return -1;
};

int RotatedArraySearch(int a[],int h,int val)
{
int peek = RotatedArrayPeek(a,h);
if(peek==-1)return(binarySearchRange(a,0,h,val));
        if(a[peek]==val)return peek;
        if(val>=a[0]) return binarySearchRange(a,0,peek-1,val);    
        if(val<a[0]) return binarySearchRange(a,peek+1,h,val);
        return peek;
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
  // int arr[] = {2,3,6,8,9,19,444,6666,8888,22222,6234544};//11
  // int arr[] = {2,3,6,8,9,19,444,6666,8888,22222,6234544};//11
  // int arr[] = {3,4,5,6,7,8,9,0,1,2};// Roteted Sorted Array
  int arr[] = {2,3,4,5,1};// Roteted Sorted Array

  // cout << binarySearch(arr,6, 10);
  // cout << ceilingNumber(arr,6, 29);
  // cout << floorNumberv(arr,6, 1);
  // cout << binarySearchInfiniteArray(arr, 22222);
  // cout << RotatedArrayPeek(arr,4);
  cout << RotatedArraySearch(arr,4,2);
  return 0;
}