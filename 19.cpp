class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		ListNode* p = head, * q = head, * old = nullptr;
		for (int i = 0; i < n; i++)
			p = p->next;
		while (p)
		{
			p = p->next;
			old = q;
			q = q->next;
		}
		if (!old)
			return head->next;
		else
			old->next = q->next;
		return head;
	}
};