class Solution {
private:
	const vector<string> v = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> ans;
	string temp;
	void fun(const string& digits, int n)
	{
		if (n == digits.size())
			ans.emplace_back(temp);
		else
		{
			const string& s = v[digits[n] - '2'];
			for (const auto x : s)
			{
				temp.push_back(x);
				fun(digits, n + 1);
				temp.pop_back();
			}
		}
		return;
	}
public:
	vector<string> letterCombinations(string digits)
	{
		if (!digits.size())
			return {};
		fun(digits, 0);
		return ans;
	}
};