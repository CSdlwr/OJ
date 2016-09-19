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
    bool isSym(TreeNode* l, TreeNode* r) {
    	if (l == NULL && r == NULL) return 1;
    	if (l == NULL || r == NULL) return 0;
    	if (l->val != r->val) return 0;
    	return isSym(l->left, r->right) && isSym(l->right, r->left);
    }
    
    bool isSymmetric(TreeNode *root) {
    	if (root == NULL) return 1;
    	return isSym(root->left, root->right);
    }
};
