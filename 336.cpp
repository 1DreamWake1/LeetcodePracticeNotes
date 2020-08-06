class Solution {
public:
	bool ishuiwen(const string& s)
	{
		int i = 0, j = s.length() - 1;
		while (i < j)
		{
			if (s[i] != s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
	vector<vector<int>> palindromePairs(vector<string>& words)
	{
		unordered_map<string, int> dic;
		vector<vector<int>> v;
		int size = words.size();
		for (int i = 0; i < size; i++)
			dic.insert(pair<string, int>(words[i], i));
		auto dic_end = dic.end();
		for (int k = 0; k < size; k++)
		{
			if (words[k].size() == 0)
				for (int i = 0; i < size; i++)
				{
					if (!ishuiwen(words[i]) || i == k)
						continue;
					v.push_back({ i,k });
					v.push_back({ k,i });
				}
			else if (words[k].size() == 1)
				continue;
			else if (!ishuiwen(words[k]))
			{
				string t(words[k]);
				reverse(t.begin(), t.end());
				auto x = dic.find(t);
				if (x != dic_end)
					v.push_back({ k,x->second });
			}
			int i = 1, j = 0;
			while (i < words[k].size())
			{
				if (ishuiwen(string(words[k], j, i)))
				{
					string t(words[k], i);
					reverse(t.begin(), t.end());
					auto x = dic.find(t);
					if (x != dic_end)
						v.push_back({ x->second,k });
				}
				i++;
			}
			j = 1;
			while (j < i)
			{
				if (ishuiwen(string(words[k], j, i)))
				{
					string t(words[k], 0, j);
					reverse(t.begin(), t.end());
					auto x = dic.find(t);
					if (x != dic_end)
						v.push_back({ k,x->second });
				}
				j++;
			}
		}
		return v;
	}
};