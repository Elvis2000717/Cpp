class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		//解决了节点个数为1或者为0的情况
		if (head == NULL || head->next == NULL)
		{
			return head;
		}
		ListNode* prev = head;
		//解决两个节点
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