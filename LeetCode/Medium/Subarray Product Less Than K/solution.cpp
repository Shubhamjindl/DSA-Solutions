class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int low = 0, high = 0, product = 1, count = 0;
        while(high < nums.size()){
            product *= nums[high];
            while(product >= k && product != 1){
                product /= nums[low];
                low++;
            }
            count += high - low +1;
            high++;
        }
        
        return count;
    }
};