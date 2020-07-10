#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 0) return false;
        int l = nums[0];
        for (int i=0; i<nums.size(); ++i){
            if (nums[i] == target) return true;
            if (i+1<nums.size() && nums[i] > nums[i+1] && l < target) return false;
        }
        return false;
    }
};


int main(){
  vector<int> a = {2,5,6,0,0,1,2};
  Solution s;
  std::cout << s.search(a, 0) << std::endl;

}
