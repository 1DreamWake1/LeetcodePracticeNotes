class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root)
	{
		long long sum = 0;
		int n = 0;
		if (!root)
			return{};
		vector<double> ans({ (double)root->val });
		queue<TreeNode*> q1, q2;
		if (root->left)
			q1.push(root->left);
		if (root->right)
			q1.push(root->right);
		while (!q1.empty())
		{
			while (!q1.empty())
			{
				TreeNode* t = q1.front();
				q1.pop();
				if (!t)
					continue;
				if (t->left)
					q2.push(t->left);
				if (t->right)
					q2.push(t->right);
				sum += t->val;
				n++;
			}
			ans.push_back((double)sum / n);
			sum = n = 0;
			q1 = move(q2);
		}
		return ans;
	}
};