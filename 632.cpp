class Solution {
public:
	vector<int> smallestRange(vector<vector<int>>& nums)
	{
		pair<int, int> ans({ 0,INT_MAX });
		int k = nums.size();
		vector<pair<int, int>> v;
		[&]()->void {
			set<pair<int, int>> s;
			for (int i = 0; i < k; i++)
				for (int j = 0; j < nums[i].size(); j++)
					s.insert({ nums[i][j],i });
			v.resize(s.size());
			copy(s.begin(), s.end(), v.begin());
		}();
		set<int> st;
		vector<int> vt(k, 0);
		for (int i = 0, j = 0; j < v.size();)
		{
			if (j && v[i].second == v[j].second)
			{
				i++;
				j++;
			}
			else
			{
				vt[v[j].second]++;
				st.insert(v[j++].second);
			}
			while (st.size() == k)
			{
				if (ans.second - ans.first > v[j - 1].first - v[i].first)
					ans = { v[i].first,v[j - 1].first };
				if (vt[v[i].second]-- == 1)
					st.erase(v[i].second);
				i++;
			}
		}
		return ans.second == INT_MAX ? vector<int>() : vector<int>({ ans.first, ans.second });
	}
};