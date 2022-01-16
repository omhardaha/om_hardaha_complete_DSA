#include <bits/stdc++.h>
using namespace std;

int main(){
  //  vector <int> arr= {10,15,-5,15,-10,5,6,2,5,7,2,5,62,14,3,63,3}; int sum = 69;
   vector <int> arr= {1,1,1,4,2,3,3,1,2,3,4,2,3,4,2,3,2,3}; int sum = 5;

  unordered_map <int,int> m ;
  int curSum = 0;
  int start = 0;
  int totalans = 0;
  int end = -1;
  for (int i = 0; i < arr.size(); i++)
  {
      curSum+=arr[i];

      if(curSum == sum){
        end = -1;
        // break;
        totalans++;
      }

     if( m.find(  (curSum-sum) ) != m.end()){
         start = m[curSum-sum] + 1;
         end = i;
        totalans++;
        //  break;
     }
     m[curSum] = i;
  }
  
cout<<"start = "<<totalans<< "end = "<<end;
 return 0;
}