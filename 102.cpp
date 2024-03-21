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

class Solution 
{
private:
    vector<vector<int>> ans;
    vector<TreeNode*> t;
    int front = 0, rear = 0;
    int cnt = 0;
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return ans;
        }
        t[rear++] = root;
        while(rear != front)
        {
            int m = rear - front;//没有这一步就无法分层
            cnt = 0;
            vector<int> a;
            for(int i = 0;i < m;i++)
            {
                TreeNode *p = t[front + i];
                a[cnt++] = p->val;
                if(p->left != nullptr)
                {
                    t[rear++] = p->left;
                    //a[cnt++] = p->left->val;
                }
                if(p->right != nullptr)
                {
                    t[rear++] = p->right;
                    //a[cnt++] = p->right->val;
                }
            }
            ans.push_back(a);
            front += m;
        }
        return ans;
    }
};

class Solution 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector <vector <int>> ret;
        if (!root) 
        {
            return ret;
        }
        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) 
        {
            int currentLevelSize = q.size();
            ret.push_back(vector <int> ());
            for (int i = 1; i <= currentLevelSize; ++i) 
            {
                auto node = q.front(); 
                q.pop();
                ret.back().push_back(node->val);
                if (node->left) 
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                } 
            }
        }
        return ret;
    }
};