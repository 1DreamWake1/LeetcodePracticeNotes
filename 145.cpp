class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> ans;
		TreeNode* prve = nullptr;
		while (root || !s.empty()) {
			while (root) {
				s.push(root);
				root = root->left;
			}
			root = s.top();
			s.pop();
			if (root->right == nullptr || root->right == prve) {
				ans.push_back(root->val);
				prve = root;
				root = nullptr;
			}
			else {
				s.push(root);
				root = root->right;
			}
		}
		return ans;
	}
};