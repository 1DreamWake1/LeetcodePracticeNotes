class Solution {
private:
	int ans = 0;
	//0 不可观测 // 1 可被观测，未装摄像头 2 已安装
	//00, 01, 02, 10, 11, 12, 20, 21, 22
	int dfs(TreeNode* root) {
		if (root == NULL) return 1;
		int left = dfs(root->left), right = dfs(root->right);
		if (left == 0 || right == 0) {
			ans++;
			return 2;
		}
		else if (left + right >= 3) return 1;
		else return 0;
	}
public:
	int minCameraCover(TreeNode* root) {
		ans = 0;
		if (root == NULL) return 0;
		if (dfs(root) == 0) ans++;
		return ans;
	}
};