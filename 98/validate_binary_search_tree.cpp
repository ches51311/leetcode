#include "define.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
    bool helper(TreeNode* root, int *lowerbound, int *upperbound) {
        if (!root) return true;
        if (lowerbound && root->val <= *lowerbound) return false;
        if (upperbound && root->val >= *upperbound) return false;
        if (!helper(root->left, lowerbound, &root->val)) return false;
        if (!helper(root->right, &root->val, upperbound)) return false;

        return true;
    }
};

int main()
{
    TreeNode *head = new TreeNode(2);
    head->left = new TreeNode(1);
    head->right = new TreeNode(3);
    Solution s;
    std::cout << s.isValidBST(head) << std::endl;
    return 0;
}



