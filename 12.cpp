class Solution {
public:
	string intToRoman(int num)
	{
		vector<int> v;
		string ans;

		while (num > 0)
		{
			v.push_back(num % 10 * pow(10, v.size()));
			num = num / 10;
		}
		//copy(v.rbegin(), v.rend(), std::ostream_iterator<int>(std::cout, " "));
		for (auto rit = v.rbegin(); rit != v.rend(); rit++)
		{
			if (*rit < 10)
				switch (*rit)
				{
				case 0:break;
				case 1:ans += "I"; break;
				case 2:ans += "II"; break;
				case 3:ans += "III"; break;
				case 4:ans += "IV"; break;
				case 5:ans += "V"; break;
				case 6:ans += "VI"; break;
				case 7:ans += "VII"; break;
				case 8:ans += "VIII"; break;
				case 9:ans += "IX"; break;
				}
			else if (*rit < 100)
				switch (*rit)
				{
				case 10:ans += "X"; break;
				case 20:ans += "XX"; break;
				case 30:ans += "XXX"; break;
				case 40:ans += "XL"; break;
				case 50:ans += "L"; break;
				case 60:ans += "LX"; break;
				case 70:ans += "LXX"; break;
				case 80:ans += "LXXX"; break;
				case 90:ans += "XC"; break;
				}
			else if (*rit < 1000)
				switch (*rit)
				{
				case 100:ans += "C"; break;
				case 200:ans += "CC"; break;
				case 300:ans += "CCC"; break;
				case 400:ans += "CD"; break;
				case 500:ans += "D"; break;
				case 600:ans += "DC"; break;
				case 700:ans += "DCC"; break;
				case 800:ans += "DCCC"; break;
				case 900:ans += "CM"; break;
				}

			else if (*rit >= 1000)
				switch (*rit)
				{
				case 1000:ans += "M"; break;
				case 2000:ans += "MM"; break;
				case 3000:ans += "MMM"; break;
				}
		}
		return ans;
	}
};