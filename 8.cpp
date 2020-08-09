class Solution {
public:
	int myAtoi(string str)
	{
		int x = 0;
		while (str[x] == ' ')
			x++;
		if (str[x] != '+' && str[x] != '-' && (str[x] < '0' || str[x] > '9'))
			return 0;
		bool is_positive = true;
		if (str[x] == '-')
			is_positive = false;
		if (str[x] == '-' || str[x] == '+')
			x++;
		int ans = 0;
		while (x < str.size() && str[x] >= '0' && str[x] <= '9')
		{
			if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && (str[x] > '7')))
				return is_positive ? INT_MAX : INT_MIN;
			ans = 10 * ans + (str[x++] - '0');
		}
		return is_positive ? ans : -ans;
	}
};