class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (!head)
			return nullptr;
		ListNode* p = head, * q = head->next, * r = head->next;
		while (p && p->next && q && q->next) {
			p = p->next = q->next;
			q = q->next = p->next;
		}
		p->next = r;
		return head;
	}
};
