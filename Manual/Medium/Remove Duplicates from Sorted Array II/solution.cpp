class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 2;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i] == nums[k -2]){
                continue;
            }
            nums[k] = nums[i];
            k++;
        }
        if(nums.size() < 2){
            return nums.size();
        }
        return k;
    }
    
};