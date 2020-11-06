#include "define.h"
#include "utilities.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        depth(root);
        return ans;
    }
private:
    int ans;
    int depth(TreeNode* root){
        if (!root) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        ans = std::max(ans, left+right);
        return std::max(left, right) + 1;
    }
};

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution s;
    std::cout << s.diameterOfBinaryTree(root) << std::endl;
}
