class Solution {
public:
	int maxNonOverlapping(vector<int>& nums, int target)
	{
		int ans = 0, sum = 0;
		unordered_set<int> s;
		s.insert(0);
		for (auto i : nums)
		{
			sum += i;
			if (s.find(sum - target) != s.end())
			{
				s.clear();
				sum = 0;
				ans++;
			}
			s.insert(sum);
		}
		return ans;
	}
};