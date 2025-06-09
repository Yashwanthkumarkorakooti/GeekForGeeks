class Solution {
  public:
    int helper(vector<int>&arr , int balance, vector<int> &dp){
        if(balance == 0) return 0 ;
        if(balance < 0) return -1 ;
        if(dp[balance] != -2) return dp[balance];
        int mini = INT_MAX ;
        for(int i=0;i<arr.size();i++){
            int count = helper(arr, balance-arr[i],dp);

            if(count != -1)
                mini = min(mini, 1+count);
        }
        dp[balance] = (mini != INT_MAX) ? mini : -1 ;
        return dp[balance];
    }
    
    int minCoins(vector<int> &coins, int sum) {
        vector<int>dp(sum+1,-2);
        return helper(coins,sum,dp);
    }
};