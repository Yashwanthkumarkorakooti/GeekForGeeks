// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        int i=0,j=0,ans =-1;
        unordered_map<char,int> m ;
        
        while(j<n){
            m[s[j]]++;
            while(m.size() > k){
                m[s[i]]--;
                if(m[s[i]] == 0) 
                    m.erase(s[i]);
                i++;
            }
            if (m.size() == k)
                ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};