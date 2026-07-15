class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int minsum = nums[0], maxkadanesum = nums[0], minans = nums[0], maxkadaneans = nums[0], arraysum = nums[0], wrappedans;
        for(int i = 1; i < nums.size(); i++){
            arraysum = arraysum + nums[i];
            minsum = min(nums[i], minsum + nums[i]);
            maxkadanesum = max(nums[i], maxkadanesum + nums[i]);
            minans = min(minsum, minans);
            maxkadaneans = max(maxkadanesum, maxkadaneans);
        }
        wrappedans = arraysum - minans;
        int ans = max(wrappedans, maxkadaneans);
        if(maxkadaneans < 0){
            return maxkadaneans;
        }
        return ans;
    }
};