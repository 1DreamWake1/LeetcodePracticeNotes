/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (!l1->val && !l1->next)
			return l2;
		if (!l2->val && !l2->next)
			return l1;
		int cf = 0, n = 0;
		ListNode* l3 = new ListNode{ 0 };
		ListNode* t = l3;
		while (l1 && l2)
		{
			n = l1->val + l2->val + cf;
			cf = n / 10;
			t->next = new ListNode{ n - cf * 10 };
			t = t->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1)
		{
			n = l1->val + cf;
			cf = n / 10;
			t->next = new ListNode{ n - cf * 10 };
			t = t->next;
			l1 = l1->next;
		}
		while (l2)
		{
			n = l2->val + cf;
			cf = n / 10;
			t->next = new ListNode{ n - cf * 10 };
			t = t->next;
			l2 = l2->next;
		}
		if (cf)
			t->next = new ListNode{ 1 };
		t = l3->next;
		delete l3;
		return t;
	}
};