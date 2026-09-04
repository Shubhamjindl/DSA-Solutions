class Solution {
  public:
    bool rec(vector<int>&arr, int n){
        if(n == 0 || n == 1){
            return true;
        }
        bool currAdjSorted = arr[n - 2] <= arr[n - 1];
        bool restAdjSorted = rec(arr, n - 1);
        if(restAdjSorted && currAdjSorted){
            return true;
        }
        else return false;
    }
    bool isSorted(vector<int>& arr) {
        return rec(arr, arr.size());
    }
};