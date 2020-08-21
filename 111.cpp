class Solution {
private:
	queue<pair<TreeNode*, int>> q;
public:
	int minDepth(TreeNode* root)
	{
		if (!root)
			return 0;
		q.push({ root, 1 });
		while (!q.empty())
		{
			TreeNode* p = q.front().first;
			int h = q.front().second;
			q.pop();
			if (!p->left && !p->right)
				return h;
			if (p->left)
				q.push({ p->left,h + 1 });
			if (p->right)
				q.push({ p->right,h + 1 });
		}
		return -1;
	}
};