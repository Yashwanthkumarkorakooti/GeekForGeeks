//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void merge(vector<int>& arr, int left,int mid,int right){
        
        int i = left , j= mid +1 , k = 0 ;
        int n = right-left+1;
        vector<int>new_arr(n);
        
        while(i <= mid && j <= right){
            if(arr[i] < arr[j]){
                new_arr[k] = arr[i];
                i++;
                k++;
            }
            else{
                new_arr[k] = arr[j];
                j++;
                k++;
            }
        }
        
        while(i <= mid){
            new_arr[k] = arr[i];
            i++;
            k++;
        }
        while(j <= right){
            new_arr[k] = arr[j];
            j++;
            k++;
        }
        
        for(int c=0;c<=n-1;c++){
            arr[left+c] = new_arr[c];
        }
        
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        
        if(l == r){
            return;
        }
        
        int mid = (l+r)/2 ;
        mergeSort(arr, l,mid);
        mergeSort(arr, mid+1,r);
        merge(arr,l,mid,r);
        
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends