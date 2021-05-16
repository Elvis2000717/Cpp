class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		queue<TreeNode*> q;
		vector<int> ans;

		if (root == nullptr)
			return ans;
		q.push(root);
		while (!q.empty())
		{
			int sz = q.size();
			for (int i = 0; i < sz; i++)
			{
				TreeNode* node = q.front();
				q.pop();
				ans.push_back(node->val);
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
		}
		return ans;
	}
};