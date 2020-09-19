class Solution {
private:
	int dfs(TreeNode* root, bool flag) {
		if (!root)
			return 0;
		int n = dfs(root->left, true) + dfs(root->right, false);
		if (flag && !root->left && !root->right)
			n += root->val;
		return n;
	}
public:
	int sumOfLeftLeaves(TreeNode* root) {
		return dfs(root, false);
	}
};