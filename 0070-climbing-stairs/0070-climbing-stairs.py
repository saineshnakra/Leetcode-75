class Solution:
    def climbStairs(self, n: int) -> int:
        if n==1 or n==0:
            return 1
        memo = {}
        memo[0] = memo[1] = 1
        for i in range(2,n+1):
            memo[i] = memo[i-1] + memo[i-2]
        return memo[n]
        