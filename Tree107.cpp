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
    
    int height(TreeNode* root)
    {
        if(root == NULL) return -1;
        int le = 1 + height(root->left);
        int re = 1+ height(root->right);
        return max(le,re);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int n = height(root) + 1;
        vector<vector<int>> v(n);
        if(root == NULL) return v;
        queue<pair<TreeNode*, int>> Q;
        Q.push({root, 0});
        while(!Q.empty()){
            auto s = Q.front();
            TreeNode* R = (s.first);
            int x = R->val;
            int l = s.second;
            v[l].push_back(x);
            Q.pop();
            if(R->left != NULL){
                Q.push(make_pair(R->left, l+1));
            }
            if(R->right != NULL){
                Q.push(make_pair(R->right, l+1));
            }
        }
        vector<vector<int>> ans;
        for(int i=n-1;i>=0;i--)
        {
            ans.push_back(v[i]);
        }
        return ans;
    }
};
