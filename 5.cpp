class Solution {
public:
	string longestPalindrome(string s)
	{
		string temp = "@";
		for (int i = 0; i < s.size(); i++)
		{
			temp += "#";
			temp += s[i];
		}
		temp += "#$";
		int size = temp.size();
		std::pair<int, int> p(0, 0);
		for (int i = 1; i < size - 1; i++)
		{
			int j;
			for (j = 1; j > 0 && j < size; j++)
				if (temp[i - j] != temp[i + j])
					break;
			if (j > p.first)
			{
				p.first = j;
				p.second = i;
			}
		}
		string ans1(temp, p.second - p.first + 1, 2 * p.first - 1);
		string ans2;
		for (int i = 0; i < ans1.size(); i++)
			if (ans1[i] != '#')
				ans2 += ans1[i];
		return ans2;
	}
};