class Solution {
public:
	string reverseWords(string s)
	{
		int size = s.size();
		for (int i = 0; i < size; i++)
		{
			int m = i;
			while (s[i] != ' ' && i < size)
				i++;
			reverse(s.begin() + m, s.begin() + i);
		}
		return s;
	}
};