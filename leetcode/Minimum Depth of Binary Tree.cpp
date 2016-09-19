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
    void solve(TreeNode* root, int dep, int &min) {
    	if (root->left == NULL && root->right == NULL && dep < min) {
    		min = dep; return ;
    	}
    	if (root->left != NULL) solve(root->left, dep+1, min);
    	if (root->right != NULL) solve(root->right, dep+1, min);
    }
    
    int minDepth(TreeNode *root) {
    	int min = 0xfffffff;
    	if (root == NULL) return 0;
    	solve(root, 1, min);
    	return min;
    }
};
