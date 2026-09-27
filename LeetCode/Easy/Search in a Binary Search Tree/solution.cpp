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
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = nullptr;
        bst(root, val, ans);
        return ans;
    }
    void bst(TreeNode* &root, int target, TreeNode* &ans){
        if(root == nullptr)
            return;
        if(root->val == target){
            ans = root;
            return;
        }
        else if(target < root->val){
            bst(root->left, target, ans);
        }
        else
            bst(root->right, target, ans);

    }
};