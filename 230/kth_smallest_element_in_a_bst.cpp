#include "define.h"

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        cnt = 0;
        this->k = k;
        inorderTraversal(root);
        return ans;
    }
private:
    void inorderTraversal(TreeNode* root){
        if (!root || cnt == k) return;
        inorderTraversal(root->left);
        cnt = cnt + 1;
        if (cnt == k) ans = root->val;
        inorderTraversal(root->right);
    }
    int cnt;
    int k;
    int ans;
};


int main()
{
    TreeNode *head = new TreeNode(3);
    head->left = new TreeNode(1);
    head->right = new TreeNode(4);
    head->left->right = new TreeNode(2);
    Solution s;
    int ans = s.kthSmallest(head, 1);
    std::cout << ans << std::endl;
    return 0;
}
