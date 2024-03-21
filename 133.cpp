#include "m.h"

class Solution 
{
public:
    vector<int> visited;
    void copy(Node* node, Node* r)
    {
        if(!visited[node->val])
        {
            r->val = node->val;
            r->neighbors = node->neighbors;
            visited[node->val] = 1;
        }
        if(node->neighbors.size() != 0)
        {
            visited.resize(100, 0);
            int len = node->neighbors.size();
            for(int i = 0; i < len;i++)
            {
                Node* n = new Node;
                copy(node->neighbors[i], n);
            }
        }
    }
    Node* cloneGraph(Node* node) 
    {
        Node* r = new Node;
        copy(node, r);
        return r;
    }
};

int main()
{

    getchar();
    return 0;
}