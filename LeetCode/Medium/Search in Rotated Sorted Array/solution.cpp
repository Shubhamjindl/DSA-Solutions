class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(target == nums[mid]){
                return mid;
            }
            // left part sorted(increasing)
            if(nums[low] <= nums[mid]){
                // and ans lies in it then
                if(target >= nums[low] && target < nums[mid]){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            // right part sorted(increasing)
            else if(nums[high] >= nums[mid]){
                // and ans lies in it then
                if(target <= nums[high] && target > nums[mid]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};