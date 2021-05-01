class Solution {
public:
	ListNode* getKthFromEnd(ListNode* head, int k) {
		ListNode* tail = head;
		ListNode* cur = head;

		while (k)
		{
			if (tail->next != 0)
			{
				tail = tail->next;
			}
			else
			{
				return head;
			}
			k--;
		}
		while (tail->next != NULL)
		{
			tail =  tail->next;
			cur = cur->next;
		}
		return cur->next;
	}
};