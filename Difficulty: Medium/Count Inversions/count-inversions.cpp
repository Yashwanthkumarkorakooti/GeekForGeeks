class Solution {
  public:
      int merge(vector<int> &arr, int left, int mid, int right){
        int i=left;
        int j = mid+1;
        int k=0;
        int n = right-left+1;
        vector<int> new_arr(n);
        
        int count = 0 ;
        while(i<=mid and j<=right){
            if(arr[i]<=arr[j])
            {
                new_arr[k]=arr[i];
                i++;
                k++;
            }
            else
            {
                new_arr[k]=arr[j];
                count += (mid - i + 1) ;
                j++;
                k++;
            }
        }
        
        while(i<=mid){
            new_arr[k]=arr[i];
            i++;
            k++;
        }
        while(j<=right){
            new_arr[k]=arr[j];
            j++;
            k++;
        }
        
        for(int c=0;c<=n-1;c++)
        {
            arr[left+c]=new_arr[c];
        }
        return count;
    }
    int merge_sort(vector<int> &arr, int left, int right){
        int count = 0 ;
        if(left==right)
        {
            return count;
        }
        int mid = (left+right)/2;
        count += merge_sort(arr, left, mid);
        count += merge_sort(arr, mid+1,right);
        
        count += merge(arr,left,mid,right);
        
        return count;
    }
    
    int inversionCount(vector<int> &arr) {
        int n = arr.size();
        int ans = merge_sort(arr,0,n-1);
        
        return ans;
    }
};