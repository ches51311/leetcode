#include "define.h"
#include "utilities.h"

class Solution {
public:
    std::vector<std::vector<int>> pathSum(TreeNode* root, int sum) {
        ans.clear();
        this->sum = sum;
        std::vector<int> a;
        pathSum(root, a, 0);
        return ans;
    }
private:
    void pathSum(TreeNode* root, std::vector<int> cur, int s) {
        if (!root) return;
        cur.push_back(root->val);
        s += root->val;
        if (s == sum && !root->left && !root->right){
            ans.push_back(cur);
        }
        else {
            pathSum(root->left, cur, s);
            pathSum(root->right, cur, s);
        }
    }
    std::vector<std::vector<int>> ans;
    int sum;
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);
    Solution s;
    std::vector<std::vector<int>> ans = s.pathSum(root, 22);
    printVecVec(ans);    
}
