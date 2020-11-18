#include "define.h"

class Solution{
public:
    int singleNumber(vector<int>& nums){
        int a = 0;
        for (auto &i : nums) a ^= i;
        return a;
    }
};

int main()
{
    vector<int> nums = {2, 2, 1};
    Solution s;
    cout << s.singleNumber(nums) << endl;
    return 0;
}
