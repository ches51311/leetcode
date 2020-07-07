#include <iostream>
#include <vector>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {      
        le.clear();
        ri.clear();
        if (!root) return true;
        if (root->left) leftorder(root->left);
        if (root->right) rightorder(root->right);
        if (le.size() != ri.size()) return false;
        for (int i=0; i<le.size(); i++)
        {
            if (le.at(i) != ri.at(i)) return false;
        }
        return true;
    }
    
private:
    void leftorder(TreeNode* root){
        le.push_back(root->val);
        if (root->left){
            leftorder(root->left);
        }
        else{
            le.push_back(NULL);
        }
        if (root->right){
            leftorder(root->right);
        }
        else{
            le.push_back(NULL);
        }
    }
    void rightorder(TreeNode* root){
        ri.push_back(root->val);
        if (root->right){
            rightorder(root->right);
        }
        else{
            ri.push_back(NULL);
        }
        if (root->left){
            rightorder(root->left);
        }
        else{
            ri.push_back(NULL);
        }
    }
    
    
    vector<int> le;
    vector<int> ri;

};


int main()
{

  TreeNode a(1);
  TreeNode b1(2);
  TreeNode b2(2);
  TreeNode c1(3);
  TreeNode c2(4);
  TreeNode c3(4);
  TreeNode c4(3);

  a.left = &b1;
  a.right = &b2;
  b1.left = &c1;
  b1.right = &c2;
  b2.left = &c3;
  b2.right = &c4;

  Solution s;

  std::cout << s.isSymmetric(&a) << std::endl;
}

