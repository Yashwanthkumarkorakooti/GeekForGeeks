// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<double,int>> kg_profits(n);
        
        for(int i=0;i<n;i++){
            kg_profits[i].first = double(val[i])/double(wt[i]);
            kg_profits[i].second = wt[i];
        }
        
        sort(kg_profits.rbegin(),kg_profits.rend());
        double ans = 0.0 ;
        
        for(int i=0;i<n;i++){
            if(kg_profits[i].second <= capacity){
                ans += kg_profits[i].first * kg_profits[i].second ;
                capacity -= kg_profits[i].second ;
            }
            else{
                ans += kg_profits[i].first * capacity;
                break;
            }
        }
        return ans;
    }
};
