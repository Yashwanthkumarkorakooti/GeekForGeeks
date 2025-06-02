// User function Template for C++
class Solution {
  public:
    int maxConsecutiveCount(vector<int> &arr) {
        int n = arr.size();
        int maxOnes = 0, maxZeroes = 0;
        int currOnes = 0, currZeroes = 0;
    
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                currOnes++;
                currZeroes = 0;
            } else if (arr[i] == 0) {
                currZeroes++;
                currOnes = 0;
            }
            maxOnes = max(maxOnes, currOnes);
            maxZeroes = max(maxZeroes, currZeroes);
        }
    
        return max(maxOnes, maxZeroes);
    }

};