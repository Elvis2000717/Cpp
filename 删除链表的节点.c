class Solution {
public:
	ListNode* deleteNode(ListNode* head, int val) {
		//Ϊ��
		if (!head)
			return NULL;
		//ֻ��һ��Ԫ��
		if (head->val == val)
			return head->next;

		ListNode* cur = head;
		ListNode* tail = head->next;

		while (tail->val != val)
		{
			if (tail->next != NULL)
			{
				cur = cur->next;
				tail = tail->next;
			}
		}
		if (tail->next == NULL)
		{
			cur->next = NULL;
			return head;
		}
		cur->next = tail->next;
		return head;
	}
};