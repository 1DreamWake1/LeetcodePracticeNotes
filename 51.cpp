class Solution {
private:
	bool isok(const vector<int>& v)
	{
		int size = v.size();
		for (int i = 0; i < size - 1; i++)
			for (int j = i + 1; j < size; j++)
				if (abs(v[i] - v[j]) == j - i)
					return false;
		return true;
	}
public:
	vector<vector<string>> solveNQueens(int n)
	{
		if (n == 1)
			return { {"Q"} };
		vector<vector<string>> ans;
		vector<int> v;
		string s;
		for (int i = 0; i < n; i++)
		{
			v.emplace_back(i);
			s += '.';
		}
		while (next_permutation(v.begin(), v.end()))
			if (isok(v))
			{
				vector<string> t(n, s);
				for (int i = 0; i < n; i++)
					t[v[i]][i] = 'Q';
				ans.emplace_back(move(t));
			}
		return ans;
	}
};