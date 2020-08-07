/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
	queue<TreeNode*> q;
public:
	void cenci(TreeNode* root, vector<int>& levels)
	{
		if (!root)
			return;
		q.push(root);
		for (TreeNode* node; !q.empty(); q.pop())
		{
			if (!(node = q.front()))
			{
				levels.push_back(777);
				continue;
			}
			levels.push_back(node->val);
			q.push(node->left);
			q.push(node->right);
		}

	}
	bool isSameTree(TreeNode* p, TreeNode* q)
	{
		vector<int> levels1, levels2;
		cenci(p, levels1);
		cenci(q, levels2);
		if (levels1.size() != levels2.size())
			return false;
		for (int i = 0; i < levels1.size(); i++)
			if (levels1[i] != levels2[i])
				return false;
		return true;
	}
};
