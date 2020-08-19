class Solution {
public:
	int countSubstrings(string s)
	{
		int size = s.size();
		if (size == 0)
			return 0;
		else if (size == 1)
			return 1;
		string str("@#");
		for (const auto& x : s)
		{
			str += x;
			str += '#';
		}
		str += '\0';
		size = str.size();
		int ans = 0;
		for (int i = 1; i < size - 1; i++)
		{
			int j = 1;
			while (str[i - j] == str[i + j])
				j++;
			ans += j / 2;
		}
		return ans;
	}
};
