#include "comm.h"

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
		}
};
class Solution {
public:
	void Mirror(TreeNode *pRoot) {
		if (pRoot == NULL)
			return;
		TreeNode *& pLeft = pRoot->left;
		TreeNode *& pRight= pRoot->right;
		if (pLeft && pRight) {
			swap(pLeft, pRight);
			Mirror(pLeft);
			Mirror(pRight);
		} else if (pLeft==NULL && pRight!=NULL) {
			swap(pLeft, pRight);
			Mirror(pLeft);
		} else if (pLeft!=NULL && pRight==NULL) {
			swap(pLeft, pRight);
			Mirror(pRight);
		} else {
			return;
		}
	}
	void swap(TreeNode *& a, TreeNode *& b) {
		TreeNode * c = a;
		a = b;
		b = c;
	}
};

int main()
{
	TreeNode * pNode = NULL;
	Solution sol;
	sol.Mirror(pNode);
}
