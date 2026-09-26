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
        TreeNode* lca = nullptr;
        rec(root, p, q, lca);
        return lca;
    }
    int rec(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &lca){
        if(root == nullptr)
            return 0;
        int rootAncestor = 0;
        if(root->val == p->val || root->val == q->val){
            rootAncestor = 1;
        }
        int leftAncestor = rec(root->left, p, q, lca);
        int rightAncestor = rec(root->right, p, q, lca);
        int ancestors = rootAncestor + leftAncestor + rightAncestor;
        if(ancestors == 2 && lca == nullptr){
            lca = root;
        }
        return ancestors;
    }
};