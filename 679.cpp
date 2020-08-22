class Solution {
private:
	static constexpr int TARGET = 24;
	static constexpr double EPSILON = 1e-6;
	static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;

	void fun(vector<double>& v1)
	{
		if (v1.size() == 1 && fabs(v1[0] - TARGET) < EPSILON)
			throw true;
		int size = v1.size();
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (i == j)
					continue;
				vector<double> v2;
				for (int k = 0; k < size; k++)
					if (k != i && k != j)
						v2.emplace_back(v1[k]);
				for (int k = 0; k < 4; k++)
				{
					if (k <2 && i>j)
						continue;
					if (k == ADD)
						v2.emplace_back(v1[i] + v1[j]);
					else if (k == MULTIPLY)
						v2.emplace_back(v1[i] * v1[j]);
					else if (k == SUBTRACT)
						v2.emplace_back(v1[i] - v1[j]);
					else if (k == DIVIDE)
						if (fabs(v1[j]) < EPSILON)
							continue;
						else
							v2.emplace_back(v1[i] / v1[j]);
					fun(v2);
					v2.pop_back();
				}
			}
		}
		return;
	}
public:
	bool judgePoint24(vector<int>& nums)
	{
		if (!nums.size())
			return false;
		vector<double> v;
		for (const auto x : nums)
			v.emplace_back(static_cast<double>(x));
		try {
			fun(v);
		}
		catch (bool)
		{
			return true;
		}
		return false;
	}
};