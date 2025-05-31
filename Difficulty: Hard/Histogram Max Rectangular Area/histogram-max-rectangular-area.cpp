class Solution {
  public:
    int getMaxArea(vector<int> &heights) {
        int n = heights.size();
        vector<int> nse(n) , pse(n);
        stack<int> stk;

        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && heights[stk.top()] >= heights[i])
                stk.pop();
            if(!stk.empty())
                nse[i] = stk.top();
            else
                nse[i] = n ;
            stk.push(i);
        }

        while(!stk.empty()) stk.pop();

         for(int i=0;i<n;i++){
            while(!stk.empty() && heights[stk.top()] > heights[i])
                stk.pop();
            if(!stk.empty())
                pse[i] = stk.top();
            else
                pse[i] = -1 ;
            stk.push(i);
        }

        int ans = -1 ;
        for(int i=0;i<n;i++){
            ans = max(ans,(nse[i]-pse[i]-1)*heights[i]);
        }
        return ans;
    }
};
