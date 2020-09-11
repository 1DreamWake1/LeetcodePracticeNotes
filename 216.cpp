class Solution {
private:
	int sum = 0, target = 0, size = 0;
	vector<vector<int>> ans;
	vector<int> t;
	void dfs(int n)
	{
		if (t.size() == size && sum == target)
		{
			ans.emplace_back(t);
			return;
		}
		else if (sum > target || n > 9 || t.size() > size)
			return;
		dfs(n + 1);
		t.push_back(n);
		sum += n;
		dfs(n + 1);
		t.pop_back();
		sum -= n;
		return;
	}
public:
	vector<vector<int>> combinationSum3(int k, int n)
	{
		target = n;
		size = k;
		dfs(1);
		return ans;
	}
};