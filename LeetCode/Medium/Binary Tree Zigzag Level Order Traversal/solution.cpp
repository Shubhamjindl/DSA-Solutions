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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode*>q;
        if(root == nullptr){
            return {};
            // cant return {{}} ie. 1 empty row
        }
        q.push(root);
        int levelNum = 0;
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
            if(levelNum % 2 != 0){
                reverse(temp.begin(), temp.end());
            }
            res.push_back(temp);
            levelNum++;
        }
        return res;
    }
};