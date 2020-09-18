class Solution {
private:
	vector<vector<int>> ans;
	vector<int> t;
	bitset<50> used;
	int size = 0;
	void dfs(vector<int>& nums, int n) {
		if (n == size) {
			ans.emplace_back(t);
			return;
		}
		for (int i = 0; i < size; i++) {
			if (used[i] || i && used[i - 1] && nums[i] == nums[i - 1])
				continue;
			used[i] = true;
			t[n] = nums[i];
			dfs(nums, n + 1);
			used[i] = false;
		}
		return;
	}
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		//sort(nums.begin(), nums.end());
		make_heap(nums.begin(), nums.end());
		sort_heap(nums.begin(), nums.end());
		size = nums.size();
		t.resize(size);
		dfs(nums, 0);
		return ans;
	}
};