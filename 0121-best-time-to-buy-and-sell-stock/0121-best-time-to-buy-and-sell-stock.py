class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mini = 10001
        res = 0
        for curr in prices:
            if mini>curr:
                mini = curr
            else:
                res = max(curr - mini,res)
        return res
        