class Solution {
public:
    int trap(vector<int>& arr) {
        int leftmax=0;
        int rightmax=0;
        int total=0;
        int l=0;
        int r=arr.size()-1;
        while(l<r){
            if(arr[l]<arr[r]){
                  if(arr[l]<leftmax){
                      total+=leftmax-arr[l];
                  }
                  else{
                    leftmax=arr[l];
                  }
                l++;
            }
            else {
                  if(arr[r]<rightmax){
                      total+=rightmax-arr[r];
                  }
                  else{
                    rightmax=arr[r];
                  }
                r--;
            }
        }
        return total;
    }
};