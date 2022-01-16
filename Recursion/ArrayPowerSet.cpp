#include <bits/stdc++.h>
using namespace std;

//print elements in array that sum = 5
void printSum(vector <int> s,int size,int index ,vector <int> &temp,int sum = 0 ){
if(index == size){
if(sum ==5){
    for(auto i : temp) cout<< i<<" ";
    cout<<endl;
}
return;
}

sum+=s[index];
temp.push_back(s[index]);
printSum(s,size,index +1,temp,sum);

sum-=s[index];
temp.pop_back();
printSum(s,size,index+1,temp,sum);
};

// count no. of elements set that sum = 5
int countSum(vector <int> s,int size,int index ,vector <int> &temp,int sum = 0 ){
if(index == size){
if(sum ==5)return 1;
return 0;
}

sum+=s[index];
int l = countSum(s,size,index +1,temp,sum);

sum-=s[index];
int r = countSum(s,size,index+1,temp,sum);

return r+l;

};

int main(){
   vector <int> s = {1,2,1,2,3,1,4,3};
   int n = 8;
   int index = 0;
   vector <int> temp;
  printSum(s,8,0,temp,0);

   cout<<countSum(s,8,0,temp,0);
 return 0;
}