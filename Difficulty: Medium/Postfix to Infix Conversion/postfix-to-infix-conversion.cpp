// User function Template for C++
#include<bits/stdc++.h>

class Solution {
  public:
    string postToInfix(string exp) {
        stack<string> s ;
        for(auto ch : exp){
            if(isalpha(ch) || isdigit(ch)){
                s.push(string(1,ch));
            }else{
                string y = s.top();
                s.pop();
                string x = s.top();
                s.pop();
                s.push('(' + x + ch + y + ')');
            }
        }
        return s.top();
    }
};