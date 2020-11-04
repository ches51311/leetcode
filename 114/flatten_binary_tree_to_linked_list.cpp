#include "define.h"
#include "utilities.h"

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        target = new TreeNode(root->val);
        TreeNode *head = target;
        helper(root);
        root->left = NULL;
        root->right = head->right->right;
    }
private:
    void helper(TreeNode* root){
        if (!root) return;
        target->right = new TreeNode(root->val);
        target = target->right;
        helper(root->left);
        helper(root->right);
    }
    TreeNode *target;
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->left->left = new TreeNode(3);
  root->left->right = new TreeNode(4);
  root->right = new TreeNode(5);
  root->right->right = new TreeNode(6);
  Solution s;
  s.flatten(root);
  levelTraversal(root);  
}
