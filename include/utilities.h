#include "define.h"


void preTraversal(TreeNode* p)
{
    if (!p) return;
    std::cout << p->val << ", ";
    preTraversal(p->left);
    preTraversal(p->right);
}

void inTraversal(TreeNode* p)
{
    if (!p) return;
    inTraversal(p->left);
    std::cout << p->val << ", ";
    inTraversal(p->right);
}

void postTraversal(TreeNode* p)
{
    if (!p) return;
    postTraversal(p->left);
    postTraversal(p->right);
    std::cout << p->val << ", ";
}

void levelTraversal(TreeNode* root)
{
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode* p = q.front(); q.pop();
        std::cout << p->val << ", ";
        if (p->left)  q.push(p->left);
        if (p->right) q.push(p->right);
    }
}

