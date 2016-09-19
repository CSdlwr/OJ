/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root, int& ans) {
    	int rs = -0xfffffff;
    	if (!root->left && !root->right) {
    		rs = root->val;
    		ans = ans < rs ? rs : ans;
    		return rs;
    	}
    	int l = 0, r = 0;
    	if (root->left)
    		l = helper(root->left, ans);
    	if (root->right)
    		r = helper(root->right, ans);
    	rs = root->val;
    	if (rs < root->val+l)
    		rs = root->val + l;
    	if (rs < root->val + r)
    		rs = root->val + r;
    	ans = ans < rs ? rs : ans;
    	if (ans < root->val+l+r)
    		ans = root->val+l+r;
    	return rs;
    }
    
    int maxPathSum(TreeNode* root) {
    	int ans = -0xfffffff-1;
    	if (!root) return ans;
    	helper(root, ans);
    	return ans;
    }
};
