class Solution {
private:
	vector<int> temp;
	vector<vector<int>> ans;

	void fun(int cur, int last, vector<int>& nums)
	{
		if (cur == nums.size())
		{
			if (temp.size() >= 2)
				ans.push_back(temp);
			return;
		}
		if (nums[cur] >= last)
		{
			temp.push_back(nums[cur]);
			fun(cur + 1, nums[cur], nums);
			temp.pop_back();
		}
		if (nums[cur] != last)
			fun(cur + 1, last, nums);
		return;
	}
public:
	vector<vector<int>> findSubsequences(vector<int>& nums) {
		fun(0, INT_MIN, nums);
		return ans;
	}
};