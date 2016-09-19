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
    TreeNode* lv = NULL;
    
    void flatten(TreeNode *root) {
        if (root == NULL) return ;
        TreeNode *sr = root->right;
        if (lv != NULL) {
    		lv->left = NULL;
    		lv->right = root;
    	}
    	lv = root;
    	flatten(lv->left);
    	flatten(sr);
    }
};
