class Solution {
public:
	bool isMatch(string s, string p) {
		return match(s.data(), p.data());
	}
	bool match(char* s, char* p) {
		if (!*p) return !*s;
		if (*(p + 1) != '*')
			return *s == *p || (*p == '.' && *s != '\0') ? match(s + 1, p + 1) : false;
		else
			return *s == *p || (*p == '.' && *s != '\0') ? match(s, p + 2) || match(s + 1, p) : match(s, p + 2);
		//或者return (*s == *p || (*p == '.' && *s != '\0')) && match(s + 1, p) || match(s, p + 2);
	}
};
//作者：OrangeMan
//链接：https ://leetcode-cn.com/problems/regular-expression-matching/solution/cjian-ji-dai-ma-ti-jie-ming-tian-xie-by-orangeman/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。