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
		//����return (*s == *p || (*p == '.' && *s != '\0')) && match(s + 1, p) || match(s, p + 2);
	}
};
//���ߣ�OrangeMan
//���ӣ�https ://leetcode-cn.com/problems/regular-expression-matching/solution/cjian-ji-dai-ma-ti-jie-ming-tian-xie-by-orangeman/
//��Դ�����ۣ�LeetCode��
//����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������