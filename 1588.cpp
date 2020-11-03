class Solution {
public:
	int sumOddLengthSubarrays(vector<int>& arr) {
		int ans = 0;
		for (int i = 0; i < arr.size(); i++)
			ans += (((i + 2) / 2) * ((arr.size() - i + 1) / 2) + ((i + 1) / 2) * ((arr.size() - i) / 2)) * arr[i];
		return ans;
	}
};
