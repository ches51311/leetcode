#include "define.h"


void pretraversal(TreeNode* p)
{
    if (!p) return;
    std::cout << p->val << ", ";
    pretraversal(p->left);
    pretraversal(p->right);
}

