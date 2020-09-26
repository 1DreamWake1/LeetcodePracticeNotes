class Solution {
private:
	int s = 0, target = 0;
	vector<int> t;
	vector<vector<int>> ans;
	void dfs(TreeNode* root) {
		if (!root) {
			return;
		}
		t.push_back(root->val);
		s += root->val;
		if (s == target && !root->left && !root->right) {
			ans.emplace_back(t);
		}
		else {
			dfs(root->left);
			dfs(root->right);
		}
		t.pop_back();
		s -= root->val;
		return;
	}
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		target = sum;
		dfs(root);
		return ans;
	}
};