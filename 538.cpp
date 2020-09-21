class Solution {
private:
	int sum = 0;
	void dfs(TreeNode* root) {
		if (!root)
			return;
		dfs(root->right);
		root->val += sum;
		sum = root->val;
		dfs(root->left);
		return;
	}
public:
	TreeNode* convertBST(TreeNode* root) {
		dfs(root);
		return root;
	}
};