class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        int n = bills.size();
        int fives = 0 , tens = 0 , twenties = 0 ;

        for(int i=0;i<n;i++){
            if(bills[i] == 5){
                fives++;
            }
            else if(bills[i] == 10){
                tens++;
                if(fives >= 1)
                    fives--;
                else
                    return false;
            }
            else if(bills[i] == 20){
                twenties++;
                if(fives >= 1 && tens >= 1){
                    fives--;
                    tens--;
                }
                else if(fives >= 3)
                    fives -= 3 ;
                else
                    return false;
            }
        }
        return true;
    }
};