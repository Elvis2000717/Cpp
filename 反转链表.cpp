class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		//����˽ڵ����Ϊ1����Ϊ0�����
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		ListNode* prev = head;
		//��������ڵ�
		ListNode* cur = prev->next;
		prev->next = NULL;
		if (cur->next == NULL)
		{
			cur->next = prev;
			return cur;
		}

		ListNode* tail = cur->next;
		cur->next = prev;
		while (tail->next != NULL)
		{
			prev = cur;
			cur = tail;
			tail = tail->next;
			cur->next = prev;
		}
		tail->next = cur;
		return tail;
	}
};