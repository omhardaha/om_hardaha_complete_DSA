#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
        int p =0;
        while(n>0){
            p++;
            n -= 1<<((int)log2(n));
            cout<<n;
        }
        return p==13 || p==11||p==2||p==3||p==5||p==7;
    };
int main(){
   vector <int> i = { 3545,454,42,525,42,5,4,4,2,5,3,7};

//    make_heap
// for(auto j :i){
//     make_heap(i.begin(),i.end());
//     cout<<j<<endl;
// }

    make_heap(i.begin(),i.end());
    // cout<<i.front()<<endl;
    // // i.pop_back();
    
    // pop_heap(i.begin(), i.end());
    // cout<<i.front()<<endl;
    // // i.pop_back();
    
    // pop_heap(i.begin(), i.end());
    // cout<<i.front()<<endl;
    // i.pop_back();
    
   //  make_heap(i.begin(),i.end());
   //  cout<<i.front()<<endl;
   //  pop_heap(i.begin(), i.end());
   //  i.pop_back();
   //  make_heap(i.begin(),i.end());
   //  cout<<i.front()<<endl;
   //  pop_heap(i.begin(), i.end());
   //  i.pop_back();
   //  make_heap(i.begin(),i.end());
   //  cout<<i.front()<<endl;
   //  pop_heap(i.begin(), i.end());
   //  i.pop_back();
   //  cout<<i.front()<<endl;
   //  pop_heap(i.begin(), i.end());
   //  i.pop_back();
   //  cout<<i.front()<<endl;
   //  pop_heap(i.begin(), i.end());
   //  i.pop_back();
   //  cout<<i.front()<<endl;
   //  pop_heap(i.begin(), i.end());
   //  i.pop_back();
// cout<<'1'-'0';
   //  cout<<isPrime(13);
    cout<<log2(0>>1);
 return 0;
}