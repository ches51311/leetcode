#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p && q) return false;
        if (p && !q) return false;
        if (p->val != q->val) {
            return false;
        }
        bool leftcorrect = false;
        bool rightcorrect = false;
        if (p->left && q->left){
            leftcorrect = isSameTree(p->left, q->left);
        }
        if (!p->left && !q->left) leftcorrect = true;
        
        if (p->right && q->right){
            rightcorrect = isSameTree(p->right, q->right);
        }
        if (!p->right && !q->right) rightcorrect = true;
        
        if (leftcorrect && rightcorrect) {
            return true;
        }
        else{
            return false;
        }
    }

    
};

int main(){
  TreeNode a1(1), a2(2), a3(3);
  TreeNode b1(1), b2(2), b3(3);
  a1.left = &a2;
  a1.right = &a3;
  b1.left = &b2;
  b1.right = &b3;
  Solution s;
  std::cout << s.isSameTree(&a1, &b1) << std::endl;

}

