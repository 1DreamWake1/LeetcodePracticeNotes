class Solution {
private:
	vector<int> v;
	void initial(int size) {
		v.assign(size, 0);
		for (int i = 0; i < size; ++i)
			v[i] = i;
		return;
	}
	int find(int n) {
		return v[n] == n ? n : v[n] = this->find(v[n]);
	}
public:
	int findCircleNum(vector<vector<int>>& M) {
		int ans = M.size();
		this->initial(M.size());
		for (int i = 1; i < M.size(); ++i)
			for (int j = 0; j < i; ++j)
				if (M[i][j]) {
					int t1 = this->find(i);
					int t2 = this->find(j);
					if (t1 != t2)
						--ans;
					v[t1] = t2;
				}
		return ans;
	}
};
