#include <iostream>
#include <vector>
using std::vector;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i=0; i<nums.size(); i++)
        {
            if (nums.at(i) >= target)
            {
                return i;
            }
        }
        return nums.size();
        
    }
};

int main(){
  vector<int> a = {1,3,5,6};
  Solution s;
  std::cout << s.searchInsert(a, 5) << std::endl;
}
