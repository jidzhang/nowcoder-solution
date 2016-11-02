#include "comm.h"

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
	public:
		struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
			if (pre.empty()) {
				return NULL;
			}
			int root = pre[0];
			vector<int> preLeft;
			vector<int> preRight;
			vector<int> inLeft;
			vector<int> inRight;
			size_t i = 0;
			bool mark  = false;
			for (; i < in.size(); ++i) {
				if (in[i] == root) {
					mark  = true;
					continue;
				}
				if (!mark)
					inLeft.push_back(in[i]);
				else
					inRight.push_back(in[i]);
			}
			for (i = 1; i < pre.size(); ++i) {
				if (found(inLeft, pre[i]))
					preLeft.push_back(pre[i]);
				else if (found(inRight, pre[i]))
					preRight.push_back(pre[i]);
			}
			struct TreeNode * ans = new struct TreeNode(root);
			struct TreeNode * leftTree  = reConstructBinaryTree(preLeft, inLeft);
			struct TreeNode * rightTree = reConstructBinaryTree(preRight, inRight);
			ans->left = leftTree;
			ans->right = rightTree;
			return ans;
		}
		bool found(const vector<int> & array, int e) {
			for (size_t i = 0; i < array.size(); ++i) {
				if (e == array[i])
					return true;
			}
			return false;
		}
};

int main()
{
	int a[] = {1, 3, 2, 5, 4, 6, 7};
	int b[] = {2, 3, 5, 1, 4, 7, 6};
	vector<int> pre(a, a+7);
	vector<int> in(b, b+7);
	Solution sol;
	struct TreeNode * p = sol.reConstructBinaryTree(pre, in);
}
