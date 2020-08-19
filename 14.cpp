class Solution {
public:
	string longestCommonPrefix(vector<string>& strs)
	{
		string ans;
		if (!strs.size() || !strs[0].size())
			return ans;
		int i = 0;
		while (i < strs[0].size())
		{
			bool flage = true;
			char c = strs[0][i];
			for (int j = 1; j < strs.size(); j++)
				if (strs[j][i] != c)
				{
					flage = false;
					break;
				}
			if (flage)
				ans += strs[0][i++];
			else
				break;
		}
		return ans;
	}
};