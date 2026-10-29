# Leetcode: Create Grid With Exactly One Path
# https://leetcode.com/problems/create-grid-with-exactly-one-path


class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        return ['.' * n] + ['#' * (n - 1) + '.'] * (m - 1)
        

sol = Solution()
print(sol.createGrid(2, 3))