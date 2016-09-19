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
    
    void preOrder(TreeNode* root, int A[], int& cnt) {
        if (root == NULL) return;
        preOrder(root->left, A, cnt);
        A[cnt++] = root->val;
        preOrder(root->right, A, cnt);
    }
    
    bool isValidBST(TreeNode *root) {
        // if (root == NULL) return true;
        int A[10000] = {0}, cnt = 0;
        preOrder(root, A, cnt);
        int max = A[0]-1;
        for (int i = 0; i < cnt; ++i) {
            if (A[i] <= max) return false;
            else max = A[i];
        }
        return true;
    }
};
