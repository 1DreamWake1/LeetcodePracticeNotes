class Solution {
public:
	vector<string> restoreIpAddresses(string s)
	{
		if (s.size() < 4)
			return {};
		vector<string> v;
		int x, y, z;
		for (x = 0; x < 3; x++)
		{
			string s1(s, 0, x + 1);
			if (stoi(s1) > 255 || (s1.size() > 1 && s1[0] == '0'))
				continue;
			for (y = x + 1; y < x + 4; y++)
			{
				string s2(s, x + 1, y - x);
				if (stoi(s2) > 255 || (s2.size() > 1 && s2[0] == '0'))
					continue;
				for (z = y + 1; z < y + 4; z++)
				{
					if (y + 1 >= s.size() || z + 1 >= s.size())
						break;
					string s3(s, y + 1, z - y);
					string s4(s, z + 1);
					if (s4.size() == 0 || s4.size() > 3)
						continue;
					if (stoi(s3) > 255 || stoi(s4) > 255)
						continue;
					if ((s3.size() > 1 && s3[0] == '0') || (s4.size() > 1 && s4[0] == '0'))
						continue;
					string ans = s1 + "." + s2 + "." + s3 + "." + s4;
					v.push_back(ans);
				}
			}
		}
		return v;
	}
};