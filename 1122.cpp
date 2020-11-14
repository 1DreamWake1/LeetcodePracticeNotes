class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		vector<int> ans(arr1.size());
		map<int, int> m;
		for (const int& x : arr1)
			++m[x];
		int i = 0;
		for (const int& x : arr2) {
			for (int j = 0; j < m[x]; ++j)
				ans[i++] = x;
			m[x] = -1;
		}
		for (const auto& x : m) {
			if (x.second != -1)
				for (int j = 0; j < x.second; ++j)
					ans[i++] = x.first;
		}
		return ans;
	}
};
