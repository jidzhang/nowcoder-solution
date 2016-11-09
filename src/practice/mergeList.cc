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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;
		ListNode * ans = NULL;
		ListNode * p = NULL;
		while (pHead1 || pHead2) {
			if (pHead1 && pHead2) {
				int v = 0;
				if (pHead1->val < pHead2->val) {
					v = pHead1->val;
					//step
					pHead1 = pHead1->next;
					if (ans == NULL) {
						ans = new ListNode(v);
						p = ans;
					} else {
						p->next = new ListNode(v);
						p = p->next;
					}
				} else if (pHead1->val > pHead2->val) {
					v = pHead2->val;
					//step
					pHead2 = pHead2->next;
					if (ans == NULL) {
						ans = new ListNode(v);
						p = ans;
					} else {
						p->next = new ListNode(v);
						p = p->next;
					}
				} else {
					v = pHead1->val;
					//step
					pHead1 = pHead1->next;
					pHead2 = pHead2->next;
					if (ans == NULL) {
						ans = new ListNode(v);
						p = ans;
						p->next = new ListNode(v);
						p = p->next;
					} else {
						p->next = new ListNode(v);
						p = p->next;
						p->next = new ListNode(v);
						p = p->next;
					}
				}
			} else if (pHead1 == NULL) {
				p->next = pHead2;
				break;
			} else {
				p->next = pHead1;
				break;
			}
		}
		return ans;
    }
};
