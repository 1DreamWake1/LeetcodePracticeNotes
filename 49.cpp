class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ans;
		map<string, vector<string>> m;
		for (const auto& x : strs) {
			string val = x;
			sort(val.begin(), val.end());
			m[val].push_back(x);
		}
		ans.assign(m.size(), {});
		int n = 0;
		for (auto& x : m)
			ans[n++] = move(x.second);
		return ans;
	}
};
