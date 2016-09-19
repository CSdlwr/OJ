/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
TreeNode* solve(ListNode* head, int x, int y) {
	if (x >= y) return NULL;
	int m = x + (y-x)/2, v = 0;
	ListNode *p = head;
	for (int i = 0; i < m; ++i) p = p->next;
	v = p->val;
	TreeNode *root = (TreeNode*) malloc(sizeof(TreeNode));
	root->val = v;
	root->left = solve(head, x, m);
	root->right = solve(p->next, x, y-m-1);
	return root;
}

TreeNode *sortedListToBST(ListNode *head) {
    if (head == NULL) return NULL;
    int len = 0; ListNode *p = head;
    while (p) { ++len; p = p->next; }
    TreeNode *root = solve(head, 0, len);
    return root;
}
};
