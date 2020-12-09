class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
		if(!nums.size())
			return {-1, -1};
		int mid = 0, left = 0, right = nums.size() - 1;
		while(left < right){
			mid = (left + right) / 2;
			if(nums[mid] >= target)
				right = mid;
			else
				left = mid + 1;
		}
		if(nums[left] != target)
			return {-1, -1};
		right = left;
		while(right < nums.size() && nums[right] == target)
			++right;
		return {left, right - 1};
    }
};
