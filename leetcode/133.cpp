class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        GraphMap visit_map;
        return dfs(node, visit_map);
    }
private:
    typedef UndirectedGraphNode Node;
    typedef unordered_map<Node*, Node*> GraphMap;
    Node* dfs(Node* start, GraphMap& visit_map) {
        if(start == NULL) {
            return NULL;
        }
        if(visit_map.find(start) != visit_map.end()) {
            return visit_map[start];
        }
        Node* new_node = new Node(start->label);
        visit_map.insert(make_pair(start, new_node));
        for(Node* x: start->neighbors) {
            new_node->neighbors.push_back(dfs(x, visit_map));
        }
        return new_node;
    }
};
