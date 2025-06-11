// User function Template for C++
class DisjointSet{
    public:
        vector<int>parent;
        DisjointSet(int size){
            parent.resize(size,-1);
        }
        int find(int node){
            if(parent[node] < 0){
                return node;
            }
            return parent[node] = find(parent[node]);
        }
        void unionSize(int a,int b){
            int parent_a = find(a);
            int parent_b = find(b);

            if(parent_a != parent_b){
                if(parent[parent_a] < parent[parent_b]){
                    int temp = parent[parent_b];
                    parent[parent_b] = parent_a ;
                    parent[parent_a] += temp ;
                }else{
                    int temp = parent[parent_a];
                    parent[parent_a] = parent_b ;
                    parent[parent_b] += temp ;
                }
            }
        }
};
class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        DisjointSet dis_set(n);
        map<string, int> m; 
        
        for(int i=0; i<n; i++) {
            int len = accounts[i].size(); 
            for(int j=1; j<len; j++) { 
                string email = accounts[i][j];
                if(m.find(email) == m.end()) {
                    m.insert({email, i});
                } 
                else {
                    dis_set.unionSize(i, m[email]);
                }
            }
        }

        vector<vector<string>> ans(n); 
    
        for(int i=0; i<n; i++) {
            ans[i].push_back(accounts[i][0]);
        } 
        
        for(auto x : m) {
            string email = x.first;
            int node = x.second;
            int overallParent = dis_set.find(node); 
            ans[overallParent].push_back(email);
        }
        
        vector<vector<string>> ans2; 
        
        for(int i=0; i<n; i++) {
            if(dis_set.parent[i] < 0) {
                sort(ans[i].begin() + 1, ans[i].end());
                ans2.push_back(ans[i]);
            }
        } 
        
        return ans2;
    }
};
