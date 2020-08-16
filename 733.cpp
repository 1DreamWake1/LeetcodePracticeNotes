class Solution {
private:
	set<pair<int, int>> s;
	int oldColor = 0;
	void fun(const vector<vector<int>>& image, int x, int y)
	{
		if (x < 0 || y < 0 || x >= image.size() || y >= image[0].size())
			return;
		if (image[x][y] != oldColor)
			return;
		auto it = s.find({ x,y });
		if (it == s.end())
			s.insert({ x,y });
		else
			return;
		fun(image, x - 1, y);
		fun(image, x, y - 1);
		fun(image, x + 1, y);
		fun(image, x, y + 1);
		return;
	}
public:
	vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
	{
		oldColor = image[sr][sc];
		fun(image, sr, sc);
		for (const auto& it : s)
			image[it.first][it.second] = newColor;
		return image;
	}
};