class Solution {
  public:
    int characterReplacement(string& s, int k) {
        int n = s.size();
        int i=0,j=0,ans=0,maxi=0;
        vector<int> arr(26,0);

        while(j<n){
            arr[s[j]-'A']++;
            maxi = max(maxi,arr[s[j]-'A']);

            if(j-i+1-maxi > k){
                arr[s[i]-'A']--;
                i++;
            }
            if(j-i+1-maxi <= k)
                ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};