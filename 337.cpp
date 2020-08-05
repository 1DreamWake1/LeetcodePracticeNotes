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
private:
public:
	std::pair<int, int> dfs(TreeNode* root)
	{
		if (!root)
			return { 0,0 };
		auto l = dfs(root->left);
		auto r = dfs(root->right);
		return { root->val + l.second + r.second,max(l.first,l.second) + max(r.first,r.second) };
	}
	int rob(TreeNode* root)
	{
		auto x = dfs(root);
		return max(x.first, x.second);
	}
};
