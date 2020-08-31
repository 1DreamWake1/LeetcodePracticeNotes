class Solution {
private:
	vector<bool> visited;
	void dfs(vector<vector<int>>& rooms, int n)
	{
		if (visited[n])
			return;
		visited[n] = true;
		for (const auto& x : rooms[n])
			dfs(rooms, x);
		return;
	}
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms)
	{
		visited.assign(rooms.size(), false);
		dfs(rooms, 0);
		for (const auto& x : visited)
			if (!x)
				return false;
		return true;
	}
};