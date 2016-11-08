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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (k == 0) {
			return 0;
		}    
		unsigned int count = 0;
		ListNode * p = pListHead;
		for (; p; p = p->next) {
			++count;
		}
		if (count < k)
			return 0;
		p = pListHead;
		for (int i=0; i<count-k; ++i ) {
			p=p->next;
		}
		return p;
    }
};
