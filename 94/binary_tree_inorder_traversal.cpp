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
    vector<int> inorderTraversal(TreeNode* root) {
        if (root)  inorder(root);
        return ans;
        
    }
    void inorder(TreeNode* root){
        if (root->left) inorder(root->left);
        ans.push_back(root->val);
        if (root->right) inorder(root->right);
    }
private:
    vector<int> ans;
};

int main()
{
TreeNode one(1);
TreeNode two(2);
TreeNode three(3);

one.right = &two;
two.left = &three;

Solution s;
vector<int> ans = s.inorderTraversal(&one);
for (vector<int>::size_type i = 0; i < ans.size(); i++){
  std::cout << ans.at(i) << ", ";
}
std::cout << std::endl;
return 0;
}

