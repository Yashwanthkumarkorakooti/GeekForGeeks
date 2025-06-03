class Solution {
  public:
    int f(vector<int>&arr, int k){
        int n = arr.size();
        int i=0,j=0,ans=0,sum=0 ;
        
        while(j<n){
            sum += arr[j];
            
            while(sum > k){
                sum -= arr[i];
                i++;
            }
            ans += j-i+1;
            j++;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& arr, int target) {
        return f(arr,target) - f(arr,target-1);
    }
};