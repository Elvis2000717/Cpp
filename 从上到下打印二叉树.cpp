class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		//存储每一层节点
		queue<TreeNode*> q;
		//存储返回值
		vector<vector<int>> ans;
		//处理特殊情况
		if (root == nullptr)
			return ans;

		q.push(root);
		while (!q.empty())
		{
			int sz = q.size();
			vector(int) ret;
			for (int i = 0; i < sz; i++)
			{
				//取队顶元素
				TreeNode* node = q.front();
				//出队
				q.pop();

				ret.push_back(node->val);
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.pish(node->right);
			}
			ans.push_back(ret);
		}
		return ans;
	}
};