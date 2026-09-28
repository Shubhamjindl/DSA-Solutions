/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < q->val)
            return rec(root, p, q);
        else
            return rec(root, q, p);
    }
    TreeNode* rec(TreeNode* root, TreeNode* p, TreeNode* q){
        if(p->val < root->val && q->val > root->val){
            return root;
        }
        TreeNode *lca;
        if(p->val == root->val || q->val == root->val){
            lca = root;
        }
        else if(p->val < root->val && q->val < root->val){
            lca = rec(root->left, p, q);
        }
        else{
            lca = rec(root->right, p, q);
        }
        return lca;
    }
};