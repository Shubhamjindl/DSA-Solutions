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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* root2;
        rec(root, root2);
        return root2;
    }
    void rec(TreeNode* root, TreeNode *& root2){
        if(root == nullptr){
            root2 = nullptr;
            return;
        }
        root2 = new TreeNode(root->val);
        rec(root->left, root2->right);
        rec(root->right, root2->left);
    }
    
};