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
class Inorder{
    stack<TreeNode*>st;
    TreeNode* curr;
    public:
    Inorder(TreeNode* root){
        curr = root;
    }
    TreeNode* next(){
        while(curr!= nullptr){
            st.push(curr);
            curr = curr->left;
        }
        TreeNode* small = st.top();
        st.pop();
        curr = small->right;
        while(curr!= nullptr){
            st.push(curr);
            curr = curr->left;
        }
        return small;
    }
};
class RevInorder{
    stack<TreeNode*>st;
    TreeNode* curr;
    public:
    RevInorder(TreeNode* root){
        curr = root;
    }
    TreeNode* next(){
        while(curr!= nullptr){
            st.push(curr);
            curr = curr->right;
        }
        TreeNode* big = st.top();
        st.pop();
        curr = big->left;
        while(curr!= nullptr){
            st.push(curr);
            curr = curr->right;
        }
        return big;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        Inorder inorder(root);
        RevInorder revInorder(root);
        TreeNode* small = inorder.next();
        TreeNode* big = revInorder.next();
        while(small != big){
            int sum = small->val + big->val;
            if(sum == k){
                return true;
            }
            else if(sum < k){
                small = inorder.next();
            }
            else
                big = revInorder.next();
        }
        return false;
    }
};