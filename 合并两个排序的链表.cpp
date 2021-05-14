class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		ListNode* cur1 = l1;
		ListNode* cur2 = l2;
		ListNode* head = new ListNode();
		ListNode* cur = head;

		while (cur1 != NULL && cur2 != NULL)
		{
			if (cur1 != NULL && cur2 != NULL && cur1->val > cur2->val)
			{
				cur->next = cur2;
				cur2 = cur2->next;
			}
			else// if (cur1 != NULL && cur2 != NULL && cur1->val < cur2->val)
			{
				cur->next = cur1;
				cur1 = cur1->next;
			}
			cur = cur->next;
		}

		if (cur1 != NULL)
		{
			cur->next = cur1;
		}
		if (cur2 != NULL)
		{
			cur->next = cur2;
		}
		cur = head->next;
		delete head;
		return cur;
	}
};