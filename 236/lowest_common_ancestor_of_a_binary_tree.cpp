#include "define.h"
#include "utilities.h"

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p=p;
        this->q=q;
        hasNode(root);
        return ans;        
    }
private:
    bool hasNode(TreeNode *root){
        if (!root) return false;
        bool t1 = (root == p || root == q);
        bool t2 = hasNode(root->left);
        bool t3 = hasNode(root->right);
        if ((t1 && t2) || (t2 && t3) || (t1 &&t3)){
            ans = root;
        }
        return (t1 || t2 || t3);
    }
    TreeNode *p;
    TreeNode *q;
    TreeNode *ans;
};

int main()
{
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  Solution s;
  std::cout << s.lowestCommonAncestor(root, root->left, root->right)->val << std::endl;
}
