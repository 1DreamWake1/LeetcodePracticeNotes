class Solution {
public:
	bool isValid(string s)
	{
		if (!s.size())
			return true;
		stack<char> st;
		st.push('\0');
		for (const auto& x : s)
		{
			if (x == '{' || x == '[' || x == '(')
				st.push(x);
			else
				if (x - st.top() == 1 || x - st.top() == 2)
					st.pop();
				else
					return false;
		}
		st.pop();
		return st.empty();
	}
};