// User function Template for C++

class Solution {
  public:
    string postToPre(string s) {
        stack<string> stk ;
        int n = s.size();
        
        for(int i=0;i<n;i++){
           if(isalpha(s[i]) || isdigit(s[i])){
               stk.push(string(1,s[i]));
           } 
           else{
               string x = stk.top();
               stk.pop();
               string y = stk.top();
               stk.pop();
               string result = s[i] + y + x ;
               stk.push(result);
           }
        }
        return stk.top();
    }
};