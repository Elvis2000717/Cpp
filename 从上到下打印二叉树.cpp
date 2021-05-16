class Solution {
public:
	vector<int> levelOrder(TreeNode* root) {
		//�洢ÿһ��ڵ�
		queue<TreeNode*> q;
		//�洢����ֵ
		vector<vector<int>> ans;
		//�����������
		if (root == nullptr)
			return ans;

		q.push(root);
		while (!q.empty())
		{
			int sz = q.size();
			vector(int) ret;
			for (int i = 0; i < sz; i++)
			{
				//ȡ�Ӷ�Ԫ��
				TreeNode* node = q.front();
				//����
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