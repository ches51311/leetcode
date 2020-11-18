#include "define.h"

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int>{-1, -1};
        int low = 0, high = nums.size()-1;
        int a;
        a = nums.size()-1;
        while(true){
            if (low+1 == a) {
                if (nums[low] == target) a--;
                else low++;
            }
            if (low == a){
                if (nums[low] != target) return vector<int>{-1, -1};
                break;
            }
            int b = (low+a)/2;
            if (nums[b] >= target){
                a = b;
            }
            else{
                low = b+1;
            }
        }
        a = 0;
        while(true){
            if (a+1 == high) {
                if (nums[high] == target) a++;
                else high--;
            }
            if (high == a){
                break;
            }
            int b = (high+a)/2;
            if (nums[b] <= target){
                a = b;
            }
            else{
                high = b-1;
            }

        }
        return vector<int>{low, high};       
    }
};

int main()
{
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    Solution s;
    vector<int> ans = s.searchRange(nums, 8);
    cout << ans[0] << ", " << ans[1] << endl;
    return 0;
}
