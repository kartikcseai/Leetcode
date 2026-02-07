class Solution {
public:
    vector<Node*> node_register;
    void dfs_helper(Node* actual, Node* clone){
        for(auto& neighbour : actual->neighbors){
            if(!node_register[neighbour->val]){
                Node* newNode = new Node(neighbour->val);
                node_register[newNode->val] = newNode;
                clone->neighbors.push_back(newNode);
                dfs_helper(neighbour, newNode);
            }
            else{
                clone->neighbors.push_back(node_register[neighbour->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) { 
        if(node == NULL) return NULL;
        Node* clone = new Node(node->val);
        node_register.resize(110, NULL);
        node_register[clone->val] = clone;
        dfs_helper(node, clone);
        return clone;
    }
};