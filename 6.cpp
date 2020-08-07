class Solution {
public:
	string convert(string s, int numRows)
	{
		if (numRows == 1)
			return s;
		string ans;
		int l = 2 * (numRows - 1);
		for (int j = 0; j < numRows; j++)
		{
			if (j == 0 || j == numRows - 1)
			{
				int i = j;
				while (i < s.size())
				{
					ans += s[i];
					i += l;
				}
			}
			else
			{
				int i = j;
				while (i < s.size())
				{
					ans += s[i];
					if ((i + l - 2 * j) < s.size())
						ans += s[i + l - 2 * j];
					i += l;
				}
			}
		}
		return ans;
	}
};