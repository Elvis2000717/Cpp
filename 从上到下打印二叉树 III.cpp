/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		queue<TreeNode*> q;
		vector<vector<int>> ans;
		if (root == nullptr)
			return ans;
		int line = 1;
		q.push(root);
		while (!q.empty())
		{
			int size = q.size();
			vector<int> ret;
			for (int i = 0; i < size; i++)
			{
				TreeNode* node = q.front();
				q.pop();
				ret.push_back(node->val);

				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
			if (line % 2 == 0)
			{
				vector<int> tmp = ret;
				for (int i = 0; i < ret.size(); i++)
				{
					int data = tmp.back();
					tmp.pop_back();
					ret[i] = data;
				}
			}
			ans.push_back(ret);
			line++;
		}
		return ans;
	}
};