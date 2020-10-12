class Solution {
private:
    int ans = INT_MAX / 2, last = INT_MIN / 2;
    void fun(TreeNode* root) {
        if (!root)
            return;
        fun(root->left);
        int t = root->val - last;
        if (t == 1)
            throw 1;
        if (t < ans)
            ans = t;
        last = root->val;
        fun(root->right);
        return;
    }
public:
    int getMinimumDifference(TreeNode* root) {
        try{
            fun(root);
        }
        catch(int){
            return 1;
        }
        return ans;
    }
};