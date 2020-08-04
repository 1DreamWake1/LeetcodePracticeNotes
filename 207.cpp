class Solution {
private:
	vector<vector<int>> edges;
	vector<int> visited;//0:没访问过，1:正在访问，2:访问过
	bool ans = true;
public:
	void dfs(int v)
	{
		visited[v] = 1;
		for (int i : edges[v])
		{
			if (visited[i] == 0)
			{
				dfs(i);
				if (!ans)
					return;
			}
			else if (visited[i] == 1)
			{
				ans = false;
				return;
			}
		}
		visited[v] = 2;
		return;
	}
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
	{
		edges.resize(numCourses);
		visited.resize(numCourses, 0);
		for (const auto& x : prerequisites)
			edges[x[1]].push_back(x[0]);
		for (int i = 0; i < numCourses && ans; i++)
			if (!visited[i])
				dfs(i);
		return ans;
	}
};