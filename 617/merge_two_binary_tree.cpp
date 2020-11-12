#include "define.h"
#include "utilities.h"

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t1) return t2;
        if (!t2) return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }    
};

int main()
{
    TreeNode* root1;
    std::vector<std::string> v1 = {"1", "3", "2", "5"};
    createTree(v1, 1, &root1);
    TreeNode* root2;
    std::vector<std::string> v2 = {"2", "1", "3", "null", "4", "null", "7"};
    createTree(v2, 1, &root2);
    Solution s;
    TreeNode* ans = s.mergeTrees(root1, root2);
    levelTraversal(ans);
    std::cout << std::endl;
}
