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
void solve(TreeNode *root, int cur, int &sum) {
	if (!root->left && !root->right) {
		sum += cur*10+root->val; return ;
	}
	if (root->left) solve(root->left, cur*10+root->val, sum);
	if (root->right) solve(root->right, cur*10+root->val, sum);
}

int sumNumbers(TreeNode *root) {
	int sum = 0;
	if(!root) return sum;
	solve(root, 0, sum);
	return sum;
}
}
