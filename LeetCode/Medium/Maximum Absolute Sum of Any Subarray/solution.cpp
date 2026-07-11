class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxEnding = nums[0], minEnding = nums[0], minAns = nums[0], maxAns = nums[0];
        for(int i = 1; i < nums.size(); i++){
            maxEnding = max(nums[i], maxEnding + nums[i]);
            minEnding = min(nums[i], minEnding + nums[i]);
            maxAns = max(maxAns, maxEnding);
            minAns = min(minAns, minEnding);
        }
        return max(abs(maxAns), abs(minAns));
    }
};