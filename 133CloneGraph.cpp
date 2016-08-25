/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m;

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        UndirectedGraphNode* cloned_node = new UndirectedGraphNode(node->label);
        m[node] = cloned_node;

        for(auto& neighbor : node->neighbors) {
        	if(m.find(neighbor) != m.end())
        		cloned_node->neighbors.push_back(m[neighbor]);
        	else {
        		UndirectedGraphNode* cloned_neighbor = cloneGraph(neighbor);
        		cloned_node->neighbors.push_back(cloned_neighbor);
        	}
        }
        return cloned_node;
    }
};