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
    bool isSameTree(TreeNode* &root1, TreeNode* &root2){
        if(root1 == nullptr && root2 == nullptr){
            return true;
        }
        if(root1 == nullptr || root2 == nullptr){
            return false;
        }
        if(root1->val != root2->val){
            return false;
        }
        bool leftNodeSame = isSameTree(root1->left, root2->left);
        bool rightNodeSame = isSameTree(root1->right, root2->right);
        return leftNodeSame && rightNodeSame;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr && subRoot == nullptr){
            return true;
        }
        if(root == nullptr || subRoot == nullptr){
            return false;
        }
        if(isSameTree(root, subRoot)){
            return true;
        }
        else{
            bool leftSameTree = isSubtree(root->left, subRoot);
            bool rightSameTree = isSubtree(root->right, subRoot);
            return leftSameTree || rightSameTree;
        }
    }
};