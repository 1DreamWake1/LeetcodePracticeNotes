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
public:
	void flatten(TreeNode* root)
	{
		TreeNode* p1 = root;
		while (p1)
		{
			if (p1->left)
			{
				if (!p1->right)
				{
					p1->right = p1->left;
					p1->left = nullptr;
				}
				else
				{
					TreeNode* p2 = p1->left;
					while (p2->right)
						p2 = p2->right;
					p2->right = p1->right;
					p1->right = p1->left;
					p1->left = nullptr;
				}
			}
			p1 = p1->right;
		}
		return;
	}
};