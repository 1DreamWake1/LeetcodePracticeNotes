class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& A) {
		int i = 1, j = 0, n = A.size();
		while (i < n) {
			if (A[i] & 1)
				i += 2;
			else {
				swap(A[i], A[j]);
				j += 2;
			}
		}
		return A;
	}
};
