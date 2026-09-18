class Solution {
public:

    void recBT(vector<vector<int>>&res, vector<int>&diary, int n, int k, int item) {
        if (diary.size() == k) {
            res.push_back(diary);
            return;
        }
        for (int itemChoice = item; itemChoice <= n; itemChoice++) {
            diary.push_back(itemChoice);
            recBT(res, diary, n, k, itemChoice + 1);
            diary.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>diary;
        recBT(res, diary, n, k, 1);
        return res;
    }
};