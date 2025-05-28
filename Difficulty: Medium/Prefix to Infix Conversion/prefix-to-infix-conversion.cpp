// User function Template for C++

class Solution {
  public:
    string preToInfix(string pre_exp) {
        stack<string> stk;
        int n = pre_exp.size();
        
        for(int i=n-1;i>=0;i--){
            if(isalpha(pre_exp[i]) || isdigit(pre_exp[i])){
                stk.push(string(1,pre_exp[i]));
            }else{
                string x = stk.top();
                stk.pop();
                string y = stk.top();
                stk.pop();
                stk.push("(" + x + pre_exp[i] + y + ")");
            }
        }
        return stk.top();
    }
};