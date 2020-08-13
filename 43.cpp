class Solution {
public:
	string multiply(string num1, string num2)
	{
		if (num1 == "0" || num2 == "0")
			return "0";
		int m = num1.size();
		int n = num2.size();
		//unique_ptr<int[]> ans_Arry(new int[m + n]{ 0 });
		int* ans_Arry(new int[m + n]{ 0 });
		for (int i = m - 1, x = 1; i >= 0; i--, x++)
			for (int j = n - 1, k = m + n - x; j >= 0; j--, k--)
				ans_Arry[k] += (num1[i] - '0') * (num2[j] - '0');
		int cf = 0;
		for (int x = m + n - 1; x >= 0; x--)
		{
			ans_Arry[x] += cf;
			if (ans_Arry[x] > 9)
			{
				cf = ans_Arry[x] / 10;
				ans_Arry[x] = ans_Arry[x] - 10 * cf;
			}
			else
				cf = 0;
		}
		string ans;
		for (int i = ans_Arry[0] ? 0 : 1, j = 0; i < m + n; i++, j++)
			ans += (ans_Arry[i] + '0');
		return ans;
	}
};