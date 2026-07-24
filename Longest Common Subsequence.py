class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m, n = len(text1), len(text2)
        memo = [[-1] * n for _ in range(m)]
        def solve(i, j):
            if i >= m or j >= n:
                return 0
            if memo[i][j] != -1:
                return memo[i][j]
            if text1[i] == text2[j]:
                memo[i][j] = 1 + solve(i + 1, j + 1)
            else:
                memo[i][j] = max(solve(i + 1, j), solve(i, j + 1))        
            return memo[i][j]
        return solve(0, 0)
