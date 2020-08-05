class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int l1 = nums1.size();
		int l2 = nums2.size();
		if (!l1)
			return l2 & 1 ? nums2[l2 / 2] : (nums2[l2 / 2 - 1] + nums2[l2 / 2]) / 2.0;
		if (!l2)
			return l1 & 1 ? nums1[l1 / 2] : (nums1[l1 / 2 - 1] + nums1[l1 / 2]) / 2.0;
		if (l1 > l2)
			return findMedianSortedArrays(nums2, nums1);
		int i = l1 & 1 ? l1 / 2 + 1 : l1 / 2;
		int j = l2 & 1 ? (l1 & 1 ? l2 / 2 : l2 / 2 + 1) : l2 / 2;
		int lim_l = 0, lim_r = l1;
		while (lim_l < lim_r)
		{
			if (j - l2 && i && nums1[i - 1] > nums2[j])//i×óÒÆ£¬¼´nums1[i-1]>nums2[j]
			{
				lim_r = i;
				int x = lim_l + (lim_r - lim_l) / 2;
				i = x - i ? x : x - 1;
				j += lim_r - i;
			}
			else if (i - l1 && j && nums1[i] < nums2[j - 1])//iÓÒÒÆ£¬¼´nums1[i]<nums2[j-1]
			{
				lim_l = i;
				int x = lim_l + (lim_r - lim_l) / 2;
				i = x - i ? x : x + 1;
				j -= i - lim_l;
			}
			else//ÕÒµ½ÖĞÎ»Êı
			{
				int lmax = max(i ? nums1[i - 1] : (j ? nums2[j - 1] : nums1[i - 1]), (j ? nums2[j - 1] : nums1[i - 1]));
				int rmin = min(j - l2 ? nums2[j] : (i - l1 ? nums1[i] : nums2[j]), i - l1 ? nums1[i] : nums2[j]);
				return (l1 + l2) & 1 ? lmax : (lmax + rmin) / 2.0;
			}
		}
		return -1;
	}
};