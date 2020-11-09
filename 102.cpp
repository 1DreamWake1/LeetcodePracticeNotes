class Solution {
private:
	vector<vector<int>> ans;
	void dfs(const TreeNode* root, int n) {
		if (!root)
			return;
		if ((int)ans.size() - 1 < n)
			ans.push_back({ root->val });
		else
			ans[n].push_back(root->val);
		dfs(root->left, n + 1);
		dfs(root->right, n + 1);
		return;
	}
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		dfs(root, 0);
		return ans;
	}
};
