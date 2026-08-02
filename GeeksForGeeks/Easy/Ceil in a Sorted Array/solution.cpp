class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int st = 0, end = arr.size() -1;
        
        while(st <= end){
            int mid = st + (end - st)/2;
            if(arr[mid] == x){
                while(mid > 0 && arr[mid -1] == x){
                    mid--;
                }
                return mid;
            }
            else if(x < arr[mid]){
                end = mid -1;
            }
            else{
                st = mid + 1;
            }
        }
        if(st >= arr.size()){
            return -1;
        }
        else{
            return st;
        }
        
    }
};