class Solution {
private:
	int sum = 0, tar = 0, size = 0;
	vector<vector<int>> ans;
	vector<int> t;
	vector<pair<int, int>> v;
	void dfs(int n)
	{
		if (sum == tar)
		{
			ans.emplace_back(t);
			return;
		}
		else if (sum > tar || n == size)
			return;
		dfs(n + 1);
		for (int i = 0; i < v[n].second; i++)
		{
			t.push_back(v[n].first);
			sum += v[n].first;
			dfs(n + 1);
		}
		for (int i = 0; i < v[n].second; i++)
		{
			t.pop_back();
			sum -= v[n].first;
		}
		return;
	}
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
	{
		tar = target;
		map<int, int> m;
		for (const auto& x : candidates)
			m[x]++;
		v.assign(m.rbegin(), m.rend());
		size = v.size();
		dfs(0);
		return ans;
	}
};