class Solution {
  public:
    int totalElements(vector<int> &fruits) {
        int n = fruits.size();
        int i=0,j=0,ans=0;
        unordered_map<int,int> m;
        while(j<n){
            m[fruits[j]]++;
            while(m.size() > 2){
                m[fruits[i]]--;
                if(m[fruits[i]] == 0)
                    m.erase(fruits[i]);
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};