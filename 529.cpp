class Solution {
private:
	int x_size = 0;
	int y_size = 0;
	void fun(int x, int y, vector<vector<char>>& board)
	{
		if (x < 0 || y < 0 || x >= x_size || y >= y_size || board[x][y] != 'E')
			return;
		int n = 0;
		const vector<pair<int, int>> vp({ {x - 1,y - 1},{x - 1,y},{x - 1,y + 1},{x,y - 1},{x,y + 1},{x + 1,y - 1},{x + 1,y},{x + 1,y + 1} });
		for (const pair<int, int>& p : vp)
		{
			if (p.first < 0 || p.second < 0 || p.first >= x_size || p.second >= y_size)
				continue;
			else if (board[p.first][p.second] == 'M')
				n++;
		}
		if (n)
			board[x][y] = '0' + n;
		else
		{
			board[x][y] = 'B';
			fun(x - 1, y - 1, board);
			fun(x - 1, y, board);
			fun(x - 1, y + 1, board);
			fun(x, y - 1, board);
			fun(x, y + 1, board);
			fun(x + 1, y - 1, board);
			fun(x + 1, y, board);
			fun(x + 1, y + 1, board);
		}
		return;
	}
public:
	vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click)
	{
		x_size = board.size();
		y_size = board[0].size();
		if (board[click[0]][click[1]] == 'M')
		{
			board[click[0]][click[1]] = 'X';
			return board;
		}
		else if (board[click[0]][click[1]] != 'E')
			return board;
		else
			fun(click[0], click[1], board);
		return board;
	}
};