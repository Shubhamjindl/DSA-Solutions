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
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return helper(root, targetSum, sum);
    }
    bool helper(TreeNode* root, int targetSum, int sum){
        if(root == nullptr){
            return false;
        }
        sum += root->val;
        if(root->left == nullptr && root->right == nullptr){
            if(sum == targetSum){
                return true;
            }
            return false;
        }
        return helper(root->left, targetSum, sum) || helper(root->right, targetSum, sum);
    }
};