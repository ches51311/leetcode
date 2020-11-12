#include "define.h"
#include "utilities.h"

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        ans = 0;
        std::vector<int> cur = {0};
        pathSum(root, sum, cur);
        return ans;
    }

private:
    void pathSum(TreeNode* root, int &sum, std::vector<int> cur){
        if (!root) return;
        for (auto &i : cur){
            i += root->val;
            if (i == sum) ans++;
        }
        cur.push_back(0);
        pathSum(root->left, sum, cur);
        pathSum(root->right, sum, cur);
    }
    int ans;
};

int main()
{
    TreeNode* root;
    std::vector<std::string> v = {"10", "5", "-3", "3", "2", "null", "11", "3", "-2", "null", "1"};
    createTree(v, 1, &root);    
    Solution s;
    std::cout << s.pathSum(root, 8) << std::endl;
}
