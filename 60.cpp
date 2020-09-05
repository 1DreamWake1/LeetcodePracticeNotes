class Solution {
private:
	static constexpr int factorial[9]{ 1,1,2,6,24,120,720,5040,40320 };
public:
	string getPermutation(int n, int k)
	{
		vector<int> nums(n, 0);
		iota(nums.begin(), nums.end(), 1);
		string ans;
		--k;
		for (int i = n - 1; i != -1; --i)
		{
			auto it = begin(nums) + k / factorial[i];
			ans += ('0' + *it);
			nums.erase(it);
			k %= factorial[i];
		}
		return ans;
	}
};