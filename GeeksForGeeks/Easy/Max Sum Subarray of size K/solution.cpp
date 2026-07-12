class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int sum = 0, maxsum = INT_MIN;
        for(int i = 0; i < k; i++){
            sum = sum + arr[i];
        }
        int low = 0, high = k - 1;
        while(high < arr.size()){
            maxsum = max(maxsum, sum);
            low++;
            high++;
            if(high == arr.size()){
                break;
            }
            sum = sum + arr[high] - arr[low - 1];
        }
        return maxsum;
    }
};