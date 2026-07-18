class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0, count = 0;
        unordered_map<int, int>mp;
        mp[0] = 1; // empty subarray has sum 0 and its remainder when divided by any no gives 0, so we store that we found remainder 0 once
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            int currRem = sum % k;
            if(currRem < 0){
                currRem += k;
            }
            count+= mp[currRem];
            mp[currRem]++;
        }
        return count;
    }
};