class Solution {
  public:
    int binaryToDecimal(string &b) {
        int n = b.size();
        int ans  = 0 ;
        int prod = 1 ;
        for(int i=n-1;i>=0;i--){
            if(b[i] == '1')
                ans += prod ;
            prod *= 2 ;
        }
        return ans;
    }
};