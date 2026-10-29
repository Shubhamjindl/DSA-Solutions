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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        bool nullSeen = false;
        while(!q.empty()){
            TreeNode* currNode = q.front();
            if(currNode){
                if(nullSeen) return false;
                q.push(currNode->left);
                q.push(currNode->right);
                q.pop();
            }
            else{
                nullSeen = true;
                q.pop();
            }
        }
        return true;
    }
};