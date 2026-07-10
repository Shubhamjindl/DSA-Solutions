class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int bestminending = nums[0], bestmaxending = nums[0], ans = nums[0];
        for(int i = 1; i < nums.size(); i++){
                int v1 = bestmaxending * nums[i];
                int v2 = bestminending * nums[i];
                int v3 = nums[i];
                bestmaxending = max(v3,max(v1, v2));
                bestminending = min(v3, min(v1, v2));
                ans = max(ans, bestmaxending );
        }
        return ans;
    }
};