class Solution {
  public:
    int priority(char ch){
        if(ch == '^') return 3;
        if(ch == '*' || ch == '/') return 2 ;
        if(ch == '+' || ch == '-') return 1 ;
        return -1;
    }
    string infixToPostfix(string& s) {
        stack<int> stk;
        string output = "";
        
        for(auto ch : s){
            if(ch >= '0' && ch <= '9' || ch >= 'A' && ch <= 'Z' ||
            ch >= 'a' && ch <= 'z'){
                output += ch;
            }
            else if(ch == '('){
                stk.push(ch);
            }
            else if(ch == ')'){
                while(!stk.empty() && stk.top() != '('){
                    output += stk.top();
                    stk.pop();
                }
                stk.pop();
            }
            else{
                while(!stk.empty() && priority(ch) <= priority(stk.top())){
                    output += stk.top();
                    stk.pop();
                }
                stk.push(ch);
            }
        }
        
        while(!stk.empty()){
            output += stk.top();
            stk.pop();
        }
        return output;
    }
};
