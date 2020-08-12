class Solution {
private:
	unordered_map<Node*, Node*> m;
public:
	Node* cloneGraph(Node* node) {
		if (!node)
			return nullptr;
		Node* new_node = nullptr;
		auto it = m.find(node);
		if (it != m.end())
			return it->second;
		else
		{
			new_node = new Node(node->val);
			m.insert({ node,new_node });
		}
		for (const auto& x : node->neighbors)
			new_node->neighbors.push_back(cloneGraph(x));
		return new_node;
	}
};