class Solution {
public:
	int countBinarySubstrings(string s)
	{
		int ans = 0;
		int i = 0, j = 1, size = s.size();
		while (j < size && s[i] == s[j])
			j++;
		int  k = j + 1;
		while (j < size)
		{
			while (k < size && s[j] == s[k])
				k++;
			ans += j - i < k - j ? j - i : k - j;
			i = j;
			j = k;
			k = j + 1;
		}
		return ans;
	}
};