class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int>used;
        vector<int>diary;
        vector<vector<int>>res;
        recBT(res, diary, used, nums, -1);
        return res;
    }
    void recBT(vector<vector<int>>&res, vector<int>&diary, unordered_set<int>&used, vector<int>& nums, int idx){
        if(diary.size() == nums.size()){
            res.push_back(diary);
            return;
        }
        used.insert(idx);
        for(int i = 0; i < nums.size(); i++){
            if(used.count(i))
                continue;
            diary.push_back(nums[i]);
            recBT(res, diary, used, nums, i);
            diary.pop_back();
            used.erase(i);
        }
    }
};