class Solution {
private:
    vector<int> v;
    TreeNode* fun(int L, int R)
    {
        if (L > R)
            return nullptr;
        int center = (L + R) / 2;
        return L == R ? new TreeNode(v[center]) : new TreeNode(v[center], fun(L, center - 1), fun(center + 1, R));
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head)
            return nullptr;
        for (ListNode* p = head; p; p = p->next)
            v.push_back(p->val);
        return fun(0, v.size() - 1);
    }
};
