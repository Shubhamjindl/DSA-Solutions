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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode*>q;
        if(root == nullptr){
            return {};
            // cant return {{}} ie. 1 empty row
        }
        q.push(root);
        while(!q.empty()){
            int levelSize = q.size();
            vector<int>temp;
            while(levelSize--){
                TreeNode *n = q.front();
                q.pop();
                temp.push_back(n->val);
                if(n->left != nullptr)
                    q.push(n->left);
                if(n->right != nullptr)
                    q.push(n->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};