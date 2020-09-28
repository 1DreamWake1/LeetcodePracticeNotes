class Solution {
private:
	queue<Node*> q1, q2;
public:
	Node* connect(Node* root) {
		if (root)
			q1.push(root);
		else
			return nullptr;
		Node* temp;
		do {
			temp = q1.front();
			while (!q1.empty()) {
				q1.pop();
				temp->next = q1.empty() ? nullptr : q1.front();
				if (temp->left)
					q2.push(temp->left);
				if (temp->right)
					q2.push(temp->right);
				temp = temp->next;
			}
			q1 = move(q2);
		} while (!q1.empty());
		return root;
	}
};