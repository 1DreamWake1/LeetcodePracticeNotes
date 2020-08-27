class Solution {
private:
	unordered_map<string, priority_queue<string, vector<string>, std::greater<string>>> m;
	vector<string> ans;
	void dfs(const string& str)
	{
		while (m.count(str) && m[str].size() > 0)
		{
			string tmp = m[str].top();
			m[str].pop();
			dfs(move(tmp));
		}
		ans.emplace_back(str);
		return;
	}
public:
	vector<string> findItinerary(vector<vector<string>>& tickets)
	{
		for (auto& it : tickets)
			m[it[0]].emplace(it[1]);
		dfs("JFK");
		reverse(ans.begin(), ans.end());
		return ans;
	}
};