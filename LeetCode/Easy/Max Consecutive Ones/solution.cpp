class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int high = 0, count = 0, res = 0;
        while(high < nums.size()){
            if(nums[high] == 1){
                count+= 1;
                res = max(res, count);
            }
            else{
                count = 0;
            }
            high++;
        }
        return res;
    }
};