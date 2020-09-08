class Solution {
private:
	int lim = 0;
	int size = 0;
	vector<int> t;
	vector<vector<int>> ans;
	void dfs(int n)
	{
		if (t.size() + lim - n < size)
			return;
		if (t.size() == size)
		{
			ans.emplace_back(t);
			return;
		}
		t.emplace_back(n);
		dfs(n + 1);
		t.pop_back();
		dfs(n + 1);
		return;
	}
public:
	vector<vector<int>> combine(int n, int k)
	{
		lim = n + 1;
		size = k;
		dfs(1);
		return ans;
	}
};