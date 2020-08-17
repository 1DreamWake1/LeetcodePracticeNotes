class Solution {
private:
	int fun(TreeNode* root)
	{
		if (!root)
			return 0;
		int R, L;
		R = fun(root->right) + 1;
		L = fun(root->left) + 1;
		if (R - L > 1 || R - L < -1)
			throw false;
		return R > L ? R : L;
	}
public:
	bool isBalanced(TreeNode* root)
	{
		if (!root)
			return true;
		try {
			fun(root);
		}
		catch (bool)
		{
			return false;
		}
		return true;
	}
};