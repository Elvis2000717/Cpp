class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* cur1 = headA;
		ListNode* cur2 = headB;

		while (cur1 != cur2)
		{
			cur1 = cur1 != NULL ? cur1->next : headB;
			cur2 = cur2 != NULL ? cur2->next : headA;
		}
		return cur1;
	}
};