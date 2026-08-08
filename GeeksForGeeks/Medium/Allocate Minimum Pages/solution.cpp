class Solution {
  public:
    int maxPagesAllocated(const vector<int>&arr, int k, long long guess){
        long long students = 1, pages = 0;
        for(int i = 0; i < arr.size(); i++){
            if(pages + arr[i] <= guess){
                pages += arr[i];
            }
            else{
                students++;
                if(students > k){
                    return false;
                }
                pages = arr[i];
            }
        }
        return true;
    }
    int findPages(vector<int> &arr, int k) {
        if(arr.size() < k){
            return -1;
        }
        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);
        while(low < high){
            long long guess = low + (high - low)/2;
            if(maxPagesAllocated(arr, k , guess)){
                high = guess;
            }
            else{
                low = guess + 1;
            }
        }
        return high;
    }
};