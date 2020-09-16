class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root)
	{
		vector<int> ans;
		stack<TreeNode*> stk;
		while (root || !stk.empty())
		{
			while (root)
			{
				ans.push_back(root->val);
				stk.push(root->right);
				root = root->left;
			}
			root = stk.top();
			stk.pop();
		}
		return ans;
	}
};