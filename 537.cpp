class Solution {
private:
	complex<int> fun(const string& str){
		int a = 0, b = 0;
		bool flag = false;
		int i = 0, j = 0;
		if(str[i] == '-'){
			flag = true;
			++i;
			++j;
		}
		while('0' <= str[j] && str[j] <= '9')
			++j;
		a = stoi(string(str.begin() + i, str.begin() + j));
		if(flag)
			a = -a;
		i = ++j;
		flag = false;
		if(str[i] == '-'){
			flag = true;
			++i;
			++j;
		}
		while('0' <= str[j] && str[j] <= '9')
			++j;
		b = stoi(string(str.begin() + i, str.begin() + j));
		if(flag)
			b = -b;
		return complex<int>(a, b);
	}
public:
    string complexNumberMultiply(string a, string b) {
		auto ans = fun(a) * fun(b);
		return string(to_string(ans.real()) + '+' + to_string(ans.imag()) + 'i');
    }
};
