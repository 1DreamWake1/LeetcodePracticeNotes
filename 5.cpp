class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() < 2)
			return s;
		string temp(2 * s.size() + 3, '#');
		int m = 0, n = 0;
		for (int i = 0; i < s.size(); ++i)
			temp[2 * (i + 1)] = s[i];
		temp[0] = '@';
		temp[temp.size() - 1] = '$';
		for (int i = 1; i < temp.size() - 1; ++i) {
			int j = 1;
			while (temp[i - j] == temp[i + j])
				++j;
			if (j > m) {
				m = j;
				n = i;
			}
		}
		string ans(m - 1, ' ');
		for (int i = 0, j = n - m + 1; j < n + m; ++j)
			if (temp[j] != '#')
				ans[i++] = temp[j];
		return ans;
	}
};
