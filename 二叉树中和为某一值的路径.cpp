class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int target) {
		dfs(root, target);
		return res;
	}

	void dfs(TreeNode* curr, int target)
	{
		//���Կս��
		if (curr != nullptr)
		{
			//��Ŀ��ֵ���ھ�Ŀ��ֵ��ȥ��ǰ����ֵ
			target -= curr->val;
			//����ǰ����ֵ���浽·������
			path.push_back(curr->val);
			if (target != 0 || curr->left != nullptr || curr->right != nullptr)
			{
				dfs(curr->left, target);
				dfs(curr->right, target);
			}
			else
			{
				//��������Ϊ���ڵ�
				res.push_back(path);
			}
			//����
			path.pop_back();
		}
	}

private:
	//ά����ǰ·��
	vector<int> path;
	//���
	vector<vector<int>> res;
};