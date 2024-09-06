# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        left = 1
        right = n
        res = n+1
        while left<=right:
            mid = (left+right)//2
            if not isBadVersion(mid):
                if res !=n+1:
                    return res
                left = mid+1
            else:
                res = min(res, mid)
                right = mid-1
        return res
            