#include "define.h"
#include "utilities.h"

class Solution {
public:
    std::vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            std::vector<TreeNode*> z;
            return z;
        }
        return generateTrees(1, n);
    }
    std::vector<TreeNode*> generateTrees(int start, int end){
        std::vector<TreeNode*> ans;
        if (start > end) {
            ans.push_back(NULL);
            return ans;
        }
        for (int i = start; i<=end; i++){
            std::vector<TreeNode*> lefts = generateTrees(start, i-1);
            std::vector<TreeNode*> rights = generateTrees(i+1, end);
            for (int l = 0; l < lefts.size(); l++){
                for (int r = 0; r < rights.size(); r++){
                    TreeNode* head = new TreeNode(i);
                    head->left = lefts[l];
                    head->right = rights[r];
                    ans.push_back(head);                    
                }
            }

        }
        return ans;
    }
};

int main()
{
  Solution s;
  std::vector<TreeNode*> ans = s.generateTrees(3);
  for (int i=0; i<ans.size(); i++){
    pretraversal(ans[i]);
    std::cout << std::endl;
  }
  return 0;
}




