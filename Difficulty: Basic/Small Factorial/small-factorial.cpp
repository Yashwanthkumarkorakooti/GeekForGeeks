//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
  public:
    long long int find_fact(int n) {
        long long int fact = 1 ;
        for(int i=1;i<=n;i++){
            fact *= i ;
        }
        return fact ;
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	long long int ans = ob.find_fact(n);
    	cout << ans <<"\n";
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends