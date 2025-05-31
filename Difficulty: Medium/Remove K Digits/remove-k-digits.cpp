class Solution {
  public:
    string removeKdigits(string s, int k) {
        int n = s.size();
        stack<char> stk;
        
        for(int i=0;i<n;i++){
            while(k!= 0 && !stk.empty() && stk.top() > s[i]){
                stk.pop();
                k--;
            }
            stk.push(s[i]);
        }
        
        while(k!=0 && !stk.empty()){
            stk.pop();
            k--;
        }
        
        string ans = "" ;
        while(!stk.empty()){
            ans.push_back(stk.top());
            stk.pop();
        }
        
        while(ans != "" && ans.back() == '0') ans.pop_back();
        reverse(ans.begin(),ans.end());
        if(ans == "") return "0";
        return ans;
    }
};