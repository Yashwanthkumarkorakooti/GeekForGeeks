// User function template for C++
class Solution {
  public:
    // #define ll long long

    ll countSubarray(int arr[], int n, int k) {
        ll total = 0;
        ll count = 0;
    
        for (int i = 0; i < n; ++i) {
            if (arr[i] > k) {
                count = i + 1;  
            }
            total += count;
        }
    
        return total;

        
    }
};