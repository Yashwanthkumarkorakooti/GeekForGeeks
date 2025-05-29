class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n);
        stack<int> stk;
        
        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && arr[i] >= stk.top())
                stk.pop();
                
            if(!stk.empty())
                ans[i] = stk.top();
            else
                ans[i] = -1 ;
                
            stk.push(arr[i]);
        }
        return ans;
    }
};