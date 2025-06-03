class Solution {
  public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total_sum = 0 ;
        for(int i=0;i<n;i++){
            total_sum += cardPoints[i];
        }

        if(n==k) return total_sum ;

        int window_len = n-k;
        int window_sum = 0 ;
        int min_sum = total_sum ;

        for(int i=0;i<n;i++){
            window_sum += cardPoints[i];
            if(i>=window_len) window_sum -= cardPoints[i-window_len];
            if(i>=window_len-1) min_sum = min(min_sum,window_sum);
        }
        return total_sum - min_sum;
    }
};
