class Solution {
  public:
    void quickSort(vector<int>& arr, int low, int high) {
        if(low < high){
            int j = partition(arr,low,high);
            quickSort(arr,low,j-1);
            quickSort(arr,j+1,high);
        }
    }

  public:
    int partition(vector<int>& arr, int low, int high) {
        int i = low , j = high ;
        
        while(i<j){
            while(arr[i] <= arr[low] && i <= high -1) i++ ;
            while(arr[j] > arr[low] && j >= 1) j-- ;
            
            if(i < j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
        
        return j ;
    }
};