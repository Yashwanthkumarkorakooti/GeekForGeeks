
class Solution {
  public:
    bool isBalanced(string& s) {
        int n = s.size();
        stack<char> stk;
        
        for(int i=0;i<n;i++){
            if(s[i]== '[' || s[i]=='{' || s[i] == '('){
                stk.push(s[i]);
            }
            else{
                if(stk.empty()){
                    return false;
                }
                else{
                    char x = stk.top();
                    stk.pop();
                    if(x == '(' && s[i] == ')' ||
                        x == '{' && s[i] == '}' ||
                        x == '[' && s[i] == ']'
                    ){
                        continue;
                    }else{
                        return false;
                    }
                }
            }
        }
        return stk.empty();
    }
};