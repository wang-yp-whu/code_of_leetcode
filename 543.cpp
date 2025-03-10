#include "m.h"


struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* createBinaryTree(const vector<int>& values) {
    if (values.empty()) return nullptr;
    
    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (i < values.size()) {
        TreeNode* node = q.front();
        q.pop();
        
        if (values[i] != NULL) {
            node->left = new TreeNode(values[i]);
            q.push(node->left);
        }
        i++;
        
        if (i < values.size() && values[i] != NULL) {
            node->right = new TreeNode(values[i]);
            q.push(node->right);
        }
        i++;
    }
    
    return root;
}

class Solution 
{
private:
    int l_height = 0, r_height = 0;
    int h = 0;
public:
    void get_height(TreeNode* root, int height)
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            h = max(h, height);
            return;
        }
        if(root->left)
        {
            get_height(root->left, height + 1);
        }
        if(root->right)
        {
            get_height(root->right, height + 1);
        }
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(!root->left)
        {
            l_height = 0;
        }
        else
        {
            h = 0;
            get_height(root->left, 1);
            l_height = h;
        }
        if(!root->right)
        {
            r_height = 0;
        }
        else
        {
            h = 0;
            get_height(root->right, 1);
            r_height = h;
        }
        return l_height + r_height;
    }
};

class Solution {
    int ans;
    int depth(TreeNode* rt){
        if (rt == NULL) {
            return 0; // 访问到空节点了，返回0
        }
        int L = depth(rt->left); // 左儿子为根的子树的深度
        int R = depth(rt->right); // 右儿子为根的子树的深度
        ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
        return max(L, R) + 1; // 返回该节点为根的子树的深度
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
};//我理解错题意了，最大直径可以不经过根节点