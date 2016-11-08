#include "comm.h"
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
		ListNode * q = pHead;
		ListNode * p = q->next;
		ListNode * c = NULL;
		q->next = NULL;
		while (p) {
			c = p;
			p = c->next;
			c->next = q;
			q = c;
		}
		return q;
    }
	void printList(ListNode * pHead) {
		while (pHead) {
			cout << pHead->val << ' ';
			pHead = pHead->next;
		}
	}
};

int main()
{
	ListNode * pHead = new ListNode(1);
	pHead->next = new ListNode(2);
	pHead->next->next = new ListNode(3);
	Solution sol;
	sol.printList(pHead);
	pHead = sol.ReverseList(pHead);
	sol.printList(pHead);
}
