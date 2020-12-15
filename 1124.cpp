class Solution {
public:
    int longestWPI(vector<int>& hours) {
		vector<int> sum(hours.size() + 1, 0);
		stack<int> stk;
		int ans = 0;
		for(int i = 0; i < hours.size(); ++i)
			sum[i + 1] = sum[i] + (hours[i] > 8 ? 1 : -1);
		for(int i = 0; i < sum.size() - 1; ++i)
			if(!i || sum[i] < sum[stk.top()])
				stk.push(i);
		for(int j = sum.size() - 1; j >= 0 && !stk.empty(); --j){
			while(!stk.empty() && sum[j] > sum[stk.top()]){
				ans = max(ans, j - stk.top());
				stk.pop();
			}
		}
		return ans;
    }
};
