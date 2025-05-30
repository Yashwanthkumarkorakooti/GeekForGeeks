class Solution {
  public:
    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        int m = (int) 1e9 + 7 ;

        vector<int> nse(n);
        stack<int> stk;

        for(int i=n-1;i>=0;i--){
            while(!stk.empty() && arr[stk.top()] >= arr[i])
                stk.pop();

            if(!stk.empty())
                nse[i] = stk.top();
            else
                nse[i] = n ;
            stk.push(i);
        }
        
        while (!stk.empty()) stk.pop();

        vector<int> pse(n);
        for(int i=0;i<n;i++){
            while(!stk.empty() && arr[stk.top()] > arr[i])
                stk.pop();
            if(!stk.empty())
                pse[i] = stk.top();
            else
                pse[i] = -1 ;
            stk.push(i);
        }


        long long sum = 0;
        for(int i=0;i<n;i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            long long contrib = (left * right % m) * arr[i] % m;
            sum = (sum + contrib) % m;
        }

        return (int) sum;
    }
};