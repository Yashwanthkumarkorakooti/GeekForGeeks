// User function Template for C++

class Solution {
  public:
    string preToPost(string s) {
        stack <string> stk;
        int n = s.size();
        
        for(int i=n-1;i>=0;i--){
            if(isalpha(s[i]) || isdigit(s[i])){
                stk.push(string(1,s[i]));
            }else{
                string x = stk.top();
                stk.pop();
                string y = stk.top();
                stk.pop();
                string res = x + y + s[i];
                stk.push(res);
            }
        }
        return stk.top();
    }
};