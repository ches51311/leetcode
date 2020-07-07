

class Solution(object):
    def twoSum(self, nums, target):
        for i1 in range(len(nums)):
            for i2 in range(len(nums)):
                if nums[i1]+nums[i2]==target:
                    if i1!=i2:
                        return [i1,i2]

s = Solution()
ans = s.twoSum([2, 7, 11, 15], 9)
print(ans)
