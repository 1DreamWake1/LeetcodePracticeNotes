class Solution {
public:
	std::string addStrings(std::string num1, std::string num2) {
		if (num1 == "0")
			return num2;
		else if (num2 == "0")
			return num1;
		std::string num3;
		int l1 = num1.length() - 1;
		int l2 = num2.length() - 1;
		int cf = 0;
		for (; l1 >= 0 || l2 >= 0; l1--, l2--)
		{
			int x1 = l1 >= 0 ? 1 : 0;
			int x2 = l2 >= 0 ? 1 : 0;
			int m = x1 * (num1[x1 * l1] - '0') + x2 * (num2[x2 * l2] - '0') + cf;
			cf = m / 10;
			num3 += (char)(m - cf * 10) + '0';
		}
		if (cf)
			num3 += '1';
		std::reverse(num3.begin(), num3.end());
		return num3;
	}
};