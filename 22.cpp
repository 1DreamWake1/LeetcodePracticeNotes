class Solution {
public:
	vector<string> generateParenthesis(int n)
	{
		if (n == 0)
			return {};
		else if (n == 1)
			return { "()" };
		else if (n == 2)
			return { "()()","(())" };
		vector<unordered_set<string>> v;
		v.push_back({});
		v.push_back({ "()" });
		v.push_back({ "()()","(())" });
		string t = "(())";
		for (int i = 3; i <= n; i++)
		{
			t = '(' + t + ')';
			v.push_back({ t });
			for (int j = 1; j < i; j++)
			{
				for (const auto& x : v[j])
					for (const auto& y : v[i - j])
						v[i].insert(x + y);
			}
			for (const auto& x : v[i - 1])
				v[i].insert('(' + x + ')');
		}
		vector<string> ans;
		ans.assign(v[n].begin(), v[n].end());
		return ans;
	}
};