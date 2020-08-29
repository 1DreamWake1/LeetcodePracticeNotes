class Solution {
private:
	static constexpr int BASE = 26;
	static constexpr int MOD = 1e9 + 7;
public:
	string shortestPalindrome(string s)
	{
		int size = s.size();
		long long a = 0, b = 0, c = 1;
		int best = -1;
		for (int i = 0; i < size; i++)
		{
			a = ((long long)a * BASE + s[i]) % MOD;
			b = (b + (long long)c * s[i]) % MOD;
			if (a == b)
				best = i;
			c = (long long)c * BASE % MOD;
		}
		string t = best == size - 1 ? "" : string(s.rbegin(), s.rend() - best - 1);
		return t + s;
	}
};