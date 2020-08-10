class Solution {
public:
	bool isPalindrome(int x)
	{
		if (x < 0 || (x && x % 10 == 0))
			return false;
		int y;
		for (y = 0; y < x; x = x / 10)
			y = x % 10 + y * 10;
		return x == y || x == y / 10 ? true : false;
	}
};