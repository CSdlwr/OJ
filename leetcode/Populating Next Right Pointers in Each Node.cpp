/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
    	if (!root) return ;
    	queue<TreeLinkNode*> que;
    	que.push(root);
    	int ccnt = 1, ncnt = 0;
    	TreeLinkNode *cur = NULL, *t = NULL;
    	while (!que.empty()) {
    		cur = que.front(); que.pop();
    		if (!que.empty()) cur->next = que.front();
    		if (cur->left) { que.push(cur->left); ++ncnt; }
    		if (cur->right) { que.push(cur->right); ++ncnt; }
    		if (--ccnt == 0) {
    			cur->next = NULL;
    			ccnt = ncnt; ncnt = 0;
    		}
    	}
    }
};
