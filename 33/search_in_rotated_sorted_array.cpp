#include "define.h"

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        if (nums[0] > target){
            for (int i = nums.size()-1; i > 0; i--){
                if (nums[i] == target) return i;
                if ((i-1 >= 0) && nums[i] < nums[i-1]) break;
            }
        }
        else{
            for (int i = 0; i < nums.size(); i++){
                if (nums[i] == target) return i;
                if ((i+1 <= nums.size()-1) && nums[i] > nums[i+1]) break;
            }
        }
        return -1;
    }
};

int main()
{
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    Solution s;
    std::cout << s.search(nums, 0) << std::endl;
}



