#include <iostream>
#include <vector>
#include <math.h>

using std::vector;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        int p = pow(2,nums.size());
        int s = nums.size();
        int t2;
        for (int i=0; i<p; ++i){
            t2 = i;
            tmp.clear();
            for (int j=0; j<s; ++j){
                if (t2 % 2 == 1) tmp.push_back(nums[j]);
                t2 = t2/2;
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};


int main(){
  vector<int> nums = {1, 2, 3};
  Solution s;
  vector<vector<int>> ans = s.subsets(nums);
  for (vector<vector<int>>::size_type i = 0; i < ans.size(); i++){
    std::cout << "[";
    for (vector<int>::size_type j = 0; j < ans.at(i).size(); j++){
      std::cout << ans.at(i).at(j) << ", ";
    }
  std::cout << "]," << std::endl;
  }
}
