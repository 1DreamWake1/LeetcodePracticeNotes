class Solution {
private:
	constexpr static int size = 9;
	vector<bitset<9>> sx, sy, sz;
	bool fun(vector<vector<char>>& board, int x, int y)
	{
		while (x < size && board[x][y] != '.')
		{
			if (y == size - 1)
			{
				x++;
				y = 0;
			}
			else
				y++;
		}
		if (x == size)
			return true;
		for (int i = 1; i <= size; i++)
		{
			if (sx[x].test(i - 1) || sy[y].test(i - 1))
				continue;
			int z = x / 3 * 3 + y / 3;
			if (sz[z].test(i - 1))
				continue;
			sx[x][i - 1] = true;
			sy[y][i - 1] = true;
			sz[z][i - 1] = true;
			board[x][y] = i + '0';
			if (fun(board, x, y))
				return true;
			sx[x][i - 1] = false;
			sy[y][i - 1] = false;
			sz[z][i - 1] = false;
		}
		board[x][y] = '.';
		return false;
	}
public:
	void solveSudoku(vector<vector<char>>& board)
	{
		sx.resize(size);
		sy.resize(size);
		sz.resize(size);
		for (int x = 0; x < size; x++)
			for (int y = 0; y < size; y++)
				if (board[x][y] != '.')
				{
					sx[x][board[x][y] - '1'] = true;
					sy[y][board[x][y] - '1'] = true;
					sz[x / 3 * 3 + y / 3][board[x][y] - '1'] = true;
				}
		fun(board, 0, 0);
		return;
	}
};