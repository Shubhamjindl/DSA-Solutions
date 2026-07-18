class Solution {
public:
    unordered_map<int, int>mp;
    int zeroes = 0, ones = 0, diff = 0, res = 0;
    int findMaxLength(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                zeroes++;
            }
            else{
                ones++;
            }
            diff = zeroes - ones;
            if(diff == 0){
                res = max(i+1, res);
            }
            else if(mp.count(diff)){
                res = max(res, i - mp[diff]);
            }
            if(mp.count(diff) == 0){
                mp[diff] = i;
            }
            
            
        }
        return res;
        
    }
};