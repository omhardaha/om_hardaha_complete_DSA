#include <bits/stdc++.h>
using namespace std;

int main(){
   vector <int> arr= {10,15,-5,15,-10,5,6,2,5,7,2,5,62,14,3,63,3}; int sum = 69;

  unordered_map <int,int> m ;
  int curSum = 0;
  int start = 0;
  int end = -1;
  for (int i = 0; i < arr.size(); i++)
  {
      curSum+=arr[i];

      if(curSum == sum){
        end = -1;
        break;
      }

     if( m.find(  (curSum-sum) ) != m.end()){
         start = m[curSum-sum] + 1;
         end = i;
         break;
     }
     m[curSum] = i;
  }
  
cout<<"start = "<<start<< "end = "<<end;
 return 0;
}