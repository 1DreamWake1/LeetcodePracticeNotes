class Solution {
private:
	int sizex = 0, sizey = 0, sizew = 0;
	vector<vector<bool>> visited;
	bool dfs(const vector<vector<char>>& board, const string& word, int k, int x, int y)
	{
		if (x < 0 || y < 0 || x >= sizex || y >= sizey)
			return false;
		if (visited[x][y] || board[x][y] != word[k])
			return false;
		if (k == sizew)
			return true;
		visited[x][y] = true;
		if (dfs(board, word, k + 1, x, y + 1) || dfs(board, word, k + 1, x + 1, y))
			return true;
		if (dfs(board, word, k + 1, x, y - 1) || dfs(board, word, k + 1, x - 1, y))
			return true;
		visited[x][y] = false;
		return false;
	}
public:
	bool exist(vector<vector<char>>& board, string word)
	{
		sizex = board.size();
		sizey = board[0].size();
		sizew = word.size() - 1;
		visited.resize(sizex);
		for (auto& it : visited)
			it.assign(sizey, false);
		for (int x = 0; x < sizex; x++)
			for (int y = 0; y < sizey; y++)
				if (board[x][y] == word[0] && dfs(board, word, 0, x, y))
					return true;
		return false;
	}
};