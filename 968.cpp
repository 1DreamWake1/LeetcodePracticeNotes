class Solution {
private:
	int ans = 0;
	//0 ���ɹ۲� // 1 �ɱ��۲⣬δװ����ͷ 2 �Ѱ�װ
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