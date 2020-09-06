class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		int size = nums.size();
		vector<vector<int>> ans;
		if (size < 4)
			return ans;
		sort(nums.begin(), nums.end());
		int a, b, c, d;
		for (a = 0; a < size - 3; a++)
		{
			if (a && nums[a] == nums[a - 1])
				continue;
			for (b = a + 1; b < size - 2; b++)
			{
				if (b > a + 1 && nums[b] == nums[b - 1])
					continue;
				for (c = b + 1, d = size - 1; c < d;)
				{
					int t = nums[a] + nums[b] + nums[c] + nums[d];
					if (t < target)
						c++;
					else if (t > target)
						d--;
					else
					{
						ans.push_back({ nums[a],nums[b],nums[c],nums[d] });
						while (c < d && nums[c] == nums[++c])
							continue;
						while (c < d && nums[d] == nums[--d])
							continue;
					}
				}
			}
		}
		return ans;
	}
};