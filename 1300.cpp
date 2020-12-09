class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int ans = target / arr.size(), pre = INT_MAX, sum = 0;
        while(true){
            for(auto x : arr)
				sum += min(ans, x);
            if(sum == target)
				break;
            if (abs(sum-target) >= abs(pre-target)){
				--ans;
				break;
			}
            else{
                pre = sum;
                sum = 0;
                ++ans;
            }
        }
        return ans;
    }
};
