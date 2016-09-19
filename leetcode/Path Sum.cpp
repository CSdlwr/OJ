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
    bool solve(TreeNode* root, int cr, int sum) {
    	cr += root->val;
    	if (cr == sum 
    		&& (root->left == NULL && root->right == NULL)) return true;
    	if (root->left == NULL && root->right == NULL) return false;
    	if (root->left != NULL && solve(root->left, cr, sum)) return true;
    	else if (root->right != NULL) return solve(root->right, cr, sum);
    	return false;
    }
    
    bool hasPathSum(TreeNode *root, int sum) {
    	if (root == NULL) return false;
        int cr = 0;
        return solve(root, cr, sum);
    }
};
