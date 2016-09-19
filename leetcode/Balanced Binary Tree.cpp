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
    int height(TreeNode* root) {
    	if (root == NULL) return 0;
    	int l = height(root->left);
    	int r = height(root->right);
    	return l > r ? l+1 : r+1;
    }

    bool isBalanced(TreeNode* root) {
    	if (root == NULL) return true;
    	int l = height(root->left);
    	int r = height(root->right);
    	if (l - r > 1 || r - l > 1 ) return false;
    	if (isBalanced(root->left) && isBalanced(root->right)) return true;
    	return false;
    }

};
