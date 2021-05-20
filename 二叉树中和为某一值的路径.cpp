class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int target) {
		dfs(root, target);
		return res;
	}

	void dfs(TreeNode* curr, int target)
	{
		//忽略空结点
		if (curr != nullptr)
		{
			//新目标值等于旧目标值减去当前结点的值
			target -= curr->val;
			//将当前结点的值保存到路径当中
			path.push_back(curr->val);
			if (target != 0 || curr->left != nullptr || curr->right != nullptr)
			{
				dfs(curr->left, target);
				dfs(curr->right, target);
			}
			else
			{
				//满足结果且为根节点
				res.push_back(path);
			}
			//回溯
			path.pop_back();
		}
	}

private:
	//维护当前路径
	vector<int> path;
	//结果
	vector<vector<int>> res;
};