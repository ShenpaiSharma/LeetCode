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
    
    bool flag = false;
    void dfs(TreeNode* root, int sum, int &ans){
        ans += root->val;
        if(root->left != NULL){
            dfs(root->left, sum, ans);
        }
        if(root->right != NULL){
            dfs(root->right, sum, ans);
        }
        if(root->left == NULL && root->right == NULL && ans == sum) flag = true;
        ans -= root->val;
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL){
            return false;
        } 
        int ans = 0;
        dfs(root, sum , ans);
        return flag;
    }
};
