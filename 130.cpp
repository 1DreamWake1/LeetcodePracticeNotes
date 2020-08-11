class Solution {
private:
	vector<vector<char>>* pboard = nullptr;
	int pwidth = 0;
	int pheight = 0;
	set<pair<int, int>> s1;
	set<pair<int, int>> s2;
	bool flag = true;

	void findo(int j, int i)
	{
		if (s1.count({ j,i }))
			return;
		if (!j || j == pheight || !i || i == pwidth)
		{
			flag = false;
			return;
		}
		s1.insert({ j,i });
		if ((*pboard)[j - 1][i] == 'O')
			findo(j - 1, i);
		if ((*pboard)[j][i - 1] == 'O')
			findo(j, i - 1);
		if ((*pboard)[j + 1][i] == 'O')
			findo(j + 1, i);
		if ((*pboard)[j][i + 1] == 'O')
			findo(j, i + 1);
		return;
	}
public:
	void solve(vector<vector<char>>& board)
	{
		if (!board.size())
			return;
		pwidth = board[0].size() - 1;
		pheight = board.size() - 1;
		pboard = &board;
		for (int j = 1; j < pheight; j++)
			for (int i = 1; i < pwidth; i++)
				if ((*pboard)[j][i] == 'O' && s2.count({ j,i }) == 0)
				{
					findo(j, i);
					if (flag)
						for (auto& x : s1)
							board[x.first][x.second] = 'X';
					else
					{
						s2.insert(s1.begin(), s1.end());
						flag = true;
					}
					s1.clear();
				}
		return;
	}
};