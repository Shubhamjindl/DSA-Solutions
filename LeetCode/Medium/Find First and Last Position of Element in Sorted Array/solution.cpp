class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() -1;
        int leftmost = -1, rightmost = -1;
        int rightspace = nums.size() -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                if(rightmost == -1){
                    rightmost = mid;
                }
                leftmost = mid;
                high = mid - 1;
            }
            else if(target < nums[mid]){
                high = mid - 1;
                rightspace = high;
            }
            else{
                low = mid + 1;
            }
        }
        if(rightmost == -1){
            return {-1,-1};
        }
        low = rightmost; high = rightspace;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(target >= nums[mid]){
                rightmost = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return {leftmost, rightmost};
    }
};