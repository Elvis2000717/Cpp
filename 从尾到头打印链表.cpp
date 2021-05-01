class Solution {
public:
	void method(vector<int>& it, ListNode* cur)
	{
		if (cur == NULL)
			return;
		method(it, cur->next);
		it.push_back(cur->val);
	}

	vector<int> reversePrint(ListNode* head) {
		vector<int> it;
		method(it, head);
		return it;
	}
};