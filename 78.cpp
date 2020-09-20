class Solution {
private:
    vector<vector<int>> ans;
    vector<int> t;
    int size = 0;
    void dfs(const vector<int>& nums ,int n){
        if(n == size){
            ans.emplace_back(t);
            return;
        }
        dfs(nums, n + 1);
        t.push_back(nums[n]);
        dfs(nums, n + 1);
        t.pop_back();
        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        size = nums.size();
        dfs(nums,0);
        return ans;
    }
};