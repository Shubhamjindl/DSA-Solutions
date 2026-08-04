class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() -1, ans = INT_MAX;
        while(low <= high){
            int guess = low + (high - low)/2;
            if(nums[guess] <= nums[high]){
                ans = min(ans, nums[guess]);
                high = guess - 1;
            }
            else{
                low = guess + 1;
            }
        }
        return ans;
    }
};