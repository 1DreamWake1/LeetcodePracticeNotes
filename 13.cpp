class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        s += '\0';
        for (int i = s.size() - 2; i >= 0; i--)
        {
            switch(s[i])
            {
                case 'I':
                    ans = s[i + 1] == 'V' || s[i + 1] == 'X' ? ans - 1 : ans + 1;
                    break;
                case 'V':
                    ans += 5;
                    break;
                case 'X':
                    ans = s[i + 1] == 'L' || s[i + 1] == 'C' ? ans - 10 : ans + 10;
                    break;
                case 'L':
                    ans += 50;
                    break;
                case 'C':
                    ans = s[i + 1] == 'D' || s[i + 1] == 'M' ? ans - 100 : ans + 100;
                    break;
                case 'D':
                    ans += 500;
                    break;
                case 'M':
                    ans += 1000;
                    break;
            }
        }
        return ans;
    }
};
