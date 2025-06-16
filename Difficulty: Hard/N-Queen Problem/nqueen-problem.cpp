// User function Template for C++

class Solution {
  public:
    void solve(int col,vector<vector<int>> &result, vector<int>&board, vector<int>&leftrow,
                vector<int>&lowerDiag,vector<int>&upperDiag, int n){
        if(col == n){
            result.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++){
            if(leftrow[row] == 0 && lowerDiag[col+row] == 0 && upperDiag[n-1+col-row] == 0){
                board.push_back(row+1);
                leftrow[row] = 1 ;
                lowerDiag[col+row] = 1 ;
                upperDiag[n-1+col-row] = 1 ;
                solve(col+1,result,board,leftrow,lowerDiag,upperDiag,n);
                board.pop_back();
                leftrow[row] = 0 ;
                lowerDiag[col+row] = 0 ;
                upperDiag[n-1+col-row] = 0 ;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> result ;
        vector<int> board ;
        vector<int> leftrow(n,0);
        vector<int> lowerDiag(2*n-1,0);
        vector<int> upperDiag(2*n-1,0);
        solve(0,result,board,leftrow,lowerDiag,upperDiag,n);
        return result;
    }
};