class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>diary;
        recBT(res, diary, candidates, target, 0, 0);
        return res;
    }
    void recBT(vector<vector<int>>&res, vector<int>&diary, vector<int> &arr, int target, int sum, int idx){
        if(sum == target){
            res.push_back(diary);
            return;
        }
        for(int i = idx; i < arr.size(); i++){
            if(sum + arr[i] <= target){
                diary.push_back(arr[i]);
                recBT(res, diary, arr, target, sum + arr[i], i);
                diary.pop_back();
            }
        }
    }

};