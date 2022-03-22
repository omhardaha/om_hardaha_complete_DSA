#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/submissions/
int minAddToMakeValid(string s) {
        stack<int>st;
        for(auto i : s){
            if(st.empty()){
              st.push(i);
            }else{
                if(i=='('){
                 st.push(i);
                }
                else{
                    if(st.top() == '('){
                      st.pop();
                    }
                    else{
                 st.push(i);
                    }
                }
            }
        }
        return st.size();
    }
int main(){
   
 return 0;
}