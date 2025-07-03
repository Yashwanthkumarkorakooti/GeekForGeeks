class Solution {
  public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, 0);

        for (int i = 1; i < n; ++i) {
            int oneStep = dp[i - 1] + abs(height[i] - height[i - 1]);
            int twoStep = INT_MAX;
            if (i > 1)
                twoStep = dp[i - 2] + abs(height[i] - height[i - 2]);
            dp[i] = min(oneStep, twoStep);
        }
        return dp[n - 1];
    }
};
