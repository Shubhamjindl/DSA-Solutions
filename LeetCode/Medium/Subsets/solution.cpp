class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>diary;
        recBT(res, diary, nums, 0);
        return res;
    }
    void recBT(vector<vector<int>>&res, vector<int>&diary, vector<int>&nums, int idx){
        if(idx == nums.size()){
            res.push_back(diary);
            return;
        }
        recBT(res, diary, nums, idx + 1);
        diary.push_back(nums[idx]);
        recBT(res, diary, nums, idx + 1);
        diary.pop_back();
    }
};