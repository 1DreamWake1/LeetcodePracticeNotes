
class Solution {
private:
	void fun(TreeNode* root)
	{
		if (!root)
			return;
		fun(root->left);
		fun(root->right);
		swap(root->left, root->right);
		return;
	}
public:
	TreeNode* invertTree(TreeNode* root)
	{
		fun(root);
		return root;
	}
};