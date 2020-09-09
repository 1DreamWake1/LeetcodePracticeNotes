class Solution {
private:
	vector<vector<int>> ans;
	vector<int> t;
	int sum = 0, tar = 0, size = 0;
	void dfs(const vector<int>& candidates, int n)
	{
		if (sum > tar || n >= size)
			return;
		else if (sum == tar)
		{
			ans.emplace_back(t);
			return;
		}
		dfs(candidates, n + 1);
		t.push_back(candidates[n]);
		sum += candidates[n];
		dfs(candidates, n);
		t.pop_back();
		sum -= candidates[n];
		return;
	}
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		tar = target;
		size = candidates.size();
		dfs(candidates, 0);
		return ans;
	}
};