class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target)
	{
		sort(nums.begin(), nums.end());
		int ans = INT_MAX / 2;
		for (int a = 0; a < nums.size(); a++)
		{
			if (a && nums[a - 1] == nums[a])
				continue;
			int b = a + 1, c = nums.size() - 1;
			while (b < c)
			{
				int sum = nums[a] + nums[b] + nums[c];
				if (abs(sum - target) < abs(ans - target))
					ans = sum;
				if (ans == target)
					return ans;
				if (sum < target)
					while (nums[b++] == nums[b] && b < c)
						continue;
				else
					while (nums[c--] == nums[c] && b < c)
						continue;
			}
		}
		return ans;
	}
};