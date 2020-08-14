class Solution {
public:
	int maxArea(vector<int>& height)
	{
		int i = 0;
		int j = height.size() - 1;
		int ans = 0;
		while (i < j)
		{
			int s = min(height[i], height[j]) * (j - i);
			if (ans < s)
				ans = s;
			height[i] < height[j] ? i++ : j--;
		}
		return ans;
	}
};