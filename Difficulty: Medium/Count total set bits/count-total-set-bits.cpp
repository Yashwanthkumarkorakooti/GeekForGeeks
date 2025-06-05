// User function Template for C++

class Solution {
  public:
    // n: input to count the number of set bits
    // Function to return sum of count of set bits in the integers from 1 to n.

    int countSetBits(int n) {
        if (n == 0)
        return 0;

        int x = log2(n); 
    
        int bitsUpTo2PowX = x * (1 << (x - 1)); 
        int msbBits = n - (1 << x) + 1;         
        int rest = countSetBits(n - (1 << x)); 
    
        return bitsUpTo2PowX + msbBits + rest;
    }
};
