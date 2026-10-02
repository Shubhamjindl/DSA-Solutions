/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>diary;
        paths(root, targetSum, ans, diary, 0);
        return ans;
    }
    void paths(TreeNode* root, int targetSum, vector<vector<int>> &ans, vector<int>diary, int sum){
        if(root == nullptr)
            return;
        sum += root->val;
        diary.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            if(sum == targetSum){
                ans.push_back(diary);
                return;
            }
            else
                return;
        }
        paths(root->left, targetSum, ans, diary, sum);
        paths(root->right, targetSum, ans, diary, sum);
    }
};