class Solution {
public:
	bool threeConsecutiveOdds(vector<int>& arr) {
		int n = 0;
		auto the_end = arr.end();
		for (auto it = arr.begin(); it != the_end; it++) {
			if (*it & 1)
				n++;
			else
				n = 0;
			if (n == 3)
				return true;
		}
		return false;
	}
};