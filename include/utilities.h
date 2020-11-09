#include "define.h"


void preTraversal(TreeNode* p)
{
    if (!p) {
      std::cout << "null" << ", ";
      return;
    }
    std::cout << p->val << ", ";
    preTraversal(p->left);
    preTraversal(p->right);
}

void inTraversal(TreeNode* p)
{
    if (!p) {
      std::cout << "null" << ", ";
      return;
    }
    inTraversal(p->left);
    std::cout << p->val << ", ";
    inTraversal(p->right);
}

void postTraversal(TreeNode* p)
{
    if (!p) {
      std::cout << "null" << ", ";
      return;
    }
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
        if (p->left) {q.push(p->left);}
        else if (p->right) {q.push(new TreeNode(-999));}
        if (p->right) {q.push(p->right);}
        else if (p->left) {q.push(new TreeNode(-999));}
    }
}

void printVecVec(std::vector<std::vector<int>> &A)
{
    for (auto a1 : A){
        for (auto a2 : a1){
            std::cout << a2 << ", ";
        }
        std::cout << std::endl;
    }
}


void createTree(std::vector<std::string> &v, int pos, TreeNode** start)
{
    if (pos > v.size()) return;
    std::string st = v[pos-1];
    if (st == "null") return;
    int n = std::stoi(st);
    *start = new TreeNode(n);

    //int m = std::floor(std::log2(pos));
    int lp = pos*2;
    int rp = lp + 1;

    createTree(v, lp, &(*start)->left);
    createTree(v, rp, &(*start)->right);

}







