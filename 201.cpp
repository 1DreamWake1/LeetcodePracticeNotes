class Solution {
public:
	int rangeBitwiseAnd(int m, int n)
	{
		if (!m || !n)
			return 0;
		else if (m == n)
			return m;
		int a = n - m;
		unsigned t = INT_MAX;
		for (int i = 0; a >= pow(2, i); i++)
			t = t << 1;
		return m & t & n;
	}
};