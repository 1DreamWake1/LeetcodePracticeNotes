class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k)
	{
		if (nums.size() == 1)
			return nums;
		vector<pair<int, int>> v;
		unordered_map<int, int> m;
		for (const auto& x : nums)
		{
			if (!m.count(x))
			{
				m.insert({ x,v.size() });
				v.push_back({ 1,x });
				continue;
			}
			v[m[x]].first++;
		}
		sort(v.begin(), v.end());
		vector<int> ans;
		for (int i = 1; i <= k; i++)
			ans.emplace_back(v[v.size() - i].second);
		return ans;
	}
};