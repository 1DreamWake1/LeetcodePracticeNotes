class Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root)
	{
		if (!root)
			return{};
		queue<TreeNode*> q1, q2;
		vector<vector<int>> ans;
		q1.push(root);
		while (!q1.empty() || !q2.empty())
		{
			vector<int> t;
			while (!q1.empty())
			{
				TreeNode* p = q1.front();
				q1.pop();
				t.emplace_back(p->val);
				if (p->left)
					q2.push(p->left);
				if (p->right)
					q2.push(p->right);
			}
			ans.emplace_back(t);
			t.clear();
			q1 = move(q2);
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};