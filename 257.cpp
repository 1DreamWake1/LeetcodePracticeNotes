class Solution {
private:
	vector<string> ans;
	void fun(TreeNode* root, string temp)
	{
		if (!root)
			return;
		temp += std::to_string(root->val);
		if (!root->left && !root->right)
		{
			ans.emplace_back(temp);
			return;
		}
		temp += "->";
		fun(root->left, temp);
		fun(root->right, temp);
		return;
	}
public:
	vector<string> binaryTreePaths(TreeNode* root)
	{
		fun(root, "");
		return ans;
	}
};