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
    int kthSmallest(TreeNode* root, int k) {
        Inorder inorder(root);
        int ans;
        for(int i = 1; i <= k; i++){
            ans = inorder.next()->val;
        }
        return ans;
    }
};