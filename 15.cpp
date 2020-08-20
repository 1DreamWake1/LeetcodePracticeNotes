class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums)
	{
		int size = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		for (int a = 0; a < size; ++a)
		{
			if (a > 0 && nums[a] == nums[a - 1])
				continue;
			int c = size - 1;
			int target = -nums[a];
			for (int b = a + 1; b < size; ++b)
			{
				if (b > a + 1 && nums[b] == nums[b - 1])
					continue;
				while (b < c && nums[b] + nums[c] > target)
					--c;
				if (b == c)
					break;
				if (nums[b] + nums[c] == target)
					ans.push_back({ nums[a], nums[b], nums[c] });
			}
		}
		return ans;
	}
};