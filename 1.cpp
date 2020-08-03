class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		unordered_map<int, int> brother_set;
		for (int i = nums.size() - 1; i >= 0; --i) {
			auto iter = brother_set.find(nums[i]);
			if (iter != brother_set.end())
				return { i, iter->second };

			int number_brother = target - nums[i];
			brother_set[number_brother] = i;
		}
		return {};
	}
};