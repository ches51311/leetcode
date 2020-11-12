#include "define.h"
#include "utilities.h"

class Solution {
public:
    int rob(TreeNode* root) {
        int l = 0, r = 0;
        return rob(root, l, r);
    }
private:
    int rob(TreeNode* root, int &l, int &r){
        if (!root) return 0;
        // for grand child
        int ll = 0, lr = 0, rl = 0, rr = 0;
        // l, r for child sum
        l = rob(root->left, ll, lr);
        r = rob(root->right, rl, rr);
        return std::max(l+r, ll + lr + rl + rr + root->val);
    }
};

int main()
{
    TreeNode* root;
    std::vector<std::string> v = {"3", "2", "3", "null", "3", "null", "1"};
    createTree(v, 1, &root);    
    Solution s;
    std::cout << s.rob(root) << std::endl;
}
