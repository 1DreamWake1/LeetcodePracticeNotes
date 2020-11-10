class Solution {
public:
	int getWinner(vector<int>& arr, int k) {
		std::ios::sync_with_stdio(false);
		int ans = arr[0];
		int first = 0;
		int last = first + k > arr.size() - 1 ? arr.size() - 1 : first + k;
		while (true) {
			for (int i = first; i <= last; ++i)
				if (arr[first] < arr[i])
					first = i;
			if (ans == arr[first])
				break;
			ans = arr[first];
			last = first + k - 1 > arr.size() - 1 ? arr.size() - 1 : first + k - 1;
		}
		return ans;
	}
};
