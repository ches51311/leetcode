#include <iostream>
#include <vector>

class Solution {
public:
    int findDuplicate(std::vector<int>& nums) {
        int turtle = 0;
        int hare = 0;
        while(true){
            turtle = nums[turtle];
            hare = nums[nums[hare]];
            if (turtle == hare) break;
        }
        turtle = 0;
        while(true){
            turtle = nums[turtle];
            hare = nums[hare];
            if (turtle == hare) break;
        }
        return turtle;
    }
};

int main()
{
    std::vector<int> nums = {1, 3, 4, 2, 2};
    Solution s;
    std::cout << s.findDuplicate(nums) << std::endl;
    return 0;
}
