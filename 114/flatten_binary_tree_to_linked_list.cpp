#include "define.h"
#include "utilities.h"

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        q = std::queue<TreeNode*>();  
        helper(root);
        q.pop();
        while(!q.empty()){
            root->left = NULL;
            root->right = q.front();
            q.pop();
            root = root->right;
        }
    }
private:
    void helper(TreeNode* root){
        if (!root) return;
        q.push(root);
        helper(root->left);
        helper(root->right);
    }
    std::queue<TreeNode*> q;
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
