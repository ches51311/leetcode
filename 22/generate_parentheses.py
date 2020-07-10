from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def growth(n, S, left, right):
            if len(S) == 2*n:
                ans.append(S)
            if left < n:
                growth(n, S+'(', left+1, right)
            if left > right:
                growth(n, S+')', left, right+1)
        ans = []
        S=''
        growth(n, S, 0, 0)
        return ans
        


s = Solution()

print(s.generateParenthesis(3))
