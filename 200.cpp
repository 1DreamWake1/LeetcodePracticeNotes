class Solution {
private:
	int xsize = 0, ysize = 0;
	int ans = 0;
	void dfs(vector<vector<char>>& grid, int x, int y)
	{
		if (x < 0 || x == xsize || y < 0 || y == ysize || grid[x][y] == '0')
			return;
		grid[x][y] = '0';
		dfs(grid, x - 1, y);
		dfs(grid, x, y - 1);
		dfs(grid, x + 1, y);
		dfs(grid, x, y + 1);
		return;
	}
public:
	int numIslands(vector<vector<char>>& grid)
	{
		xsize = grid.size();
		if (!xsize)
			return ans;
		ysize = grid[0].size();
		for (int x = 0; x < xsize; x++)
			for (int y = 0; y < ysize; y++)
				if (grid[x][y] == '1')
				{
					dfs(grid, x, y);
					ans++;
				}
		return ans;
	}
};