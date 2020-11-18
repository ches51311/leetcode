#include "define.h"
#include "utilities.h"

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        ans.clear();
        if (nums.size() < 3) return ans;
        sort(begin(nums), end(nums));
        for (int i=0; i<nums.size() && nums[i] <=0 ; i++){
            if (i == 0 || nums[i-1] != nums[i]){
                twoSum(nums, i);                
            }
        }
        return ans;

    }
private:
    void twoSum(std::vector<int>& nums, int i){
        int low = i+1, high = nums.size()-1;
        while(low < high){
            int cnt = nums[i]+nums[low]+nums[high];
            if (cnt < 0){
                low++;
            }
            else if (cnt > 0){
                high--;
            }
            else{
                ans.push_back({nums[i], nums[low], nums[high]});
                low++;
                high--;
                while(low < high && nums[low] == nums[low-1]){
                    low++;
                }
            }
        }
        
    }
    std::vector<std::vector<int>> ans;
};


int main()
{
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution s;
    std::vector<std::vector<int>> ans = s.threeSum(nums);
    printVecVec(ans);  

}
