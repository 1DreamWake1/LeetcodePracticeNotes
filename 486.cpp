class Solution {
public:
	bool PredictTheWinner(vector<int>& nums)
	{
		int size = nums.size();
		if (!(size & 1) || size == 1)
			return true;
		vector<int> dp(nums);
		for (int i = size - 2; i >= 0; i--)
			for (int j = i + 1; j < size; j++)
				dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
		return dp[size - 1] >= 0;
	}
};