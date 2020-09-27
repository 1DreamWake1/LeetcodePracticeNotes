class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;
        if (p->val > q->val)
            swap(p, q);
        TreeNode *i = nullptr, *j = nullptr;
        if (root == p)
            i = p;
        else if (root == q)
            j = q;
        if (!i) {
            i = lowestCommonAncestor(root->left, p, q);
            if(i && i != p)
                return i;
        }
        if (!j) {
            j = lowestCommonAncestor(root->right, p, q);
            if(j && j != q)
                return j;
        }
        if (i && j)
            return root;
        else if (i)
            return i;
        else
            return j;
    }
};