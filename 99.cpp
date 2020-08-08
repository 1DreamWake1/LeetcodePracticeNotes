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
	std::multiset<int> ms;
	std::multiset<int>::iterator it;
public:
	void zhongxu(TreeNode* root)
	{
		if (!root)
			return;
		zhongxu(root->left);
		ms.insert(root->val);
		zhongxu(root->right);
	}
	void check(TreeNode* root)
	{
		if (!root)
			return;
		check(root->left);
		root->val = *it++;
		check(root->right);
	}
	void recoverTree(TreeNode* root)
	{
		zhongxu(root);
		it = ms.begin();
		check(root);
		return;
	}
};