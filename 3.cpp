class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (!s.size())
			return 0;
		int i = 0, j = 0;
		int max = 0;
		std::unordered_map<char, int> se;
		while (i != s.size())
		{
			if (se.find(s[i]) == se.end())
			{
				se.insert(std::pair<char, int>(s[i], i));
				i++;
			}
			else
			{
				int x = se.find(s[i])->second + 1;
				while (j < x)
					se.erase(s[j++]);
				se.insert(std::pair<char, int>(s[i], i));
				i++;
			}
			max = max > i - j ? max : i - j;
		}
		return max;
	}
};