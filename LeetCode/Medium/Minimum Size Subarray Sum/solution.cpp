class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0, high = 0, len = INT_MAX, res = INT_MAX, sum = 0;
        while(high < nums.size()){
            sum += nums[high];
            while(sum >= target){
                len = high - low + 1;
                res = min(res, len);
                sum = sum - nums[low];
                low++;
            }
            high++;
        }
        if(res == INT_MAX){
            return 0;
        }
        return res;
    }
};