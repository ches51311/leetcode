#include "define.h"

class Solution {
public:
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        this->pre_idx = 0;
        TreeNode *ans = helper(0, preorder.size());
        return ans;
    }
private:
    TreeNode *helper(int start, int end) {
        if (start == end) return NULL;
        int val = preorder[pre_idx];
        pre_idx++;
        TreeNode *root = new TreeNode(val);
        int index = start;
        for (; inorder[index] != val; index ++) {}
        root->left = helper(start, index);
        root->right = helper(index+1, end);
        return root;
    }
    
    std::vector<int> preorder;
    std::vector<int> inorder;
    int pre_idx;
    
};

int main()
{
  std::cout << "not yet understand this problem..." << std::endl;
  return 0;
}
