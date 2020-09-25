class Solution {
private:
	unordered_map<int, int> m;
	int n = -1;
	TreeNode* mkTree(const vector<int>postorder, int l, int r) {
		if (l > r) {
			return nullptr;
		}
		TreeNode* root = new TreeNode(postorder[n]);
		int index = m[postorder[n]];
		n--;
		root->right = mkTree(postorder, index + 1, r);
		root->left = mkTree(postorder, l, index - 1);
		return root;
	}
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		for (const auto& it : inorder) {
			m.insert({ it,++n });
		}
		return mkTree(postorder, 0, n);
	}
};