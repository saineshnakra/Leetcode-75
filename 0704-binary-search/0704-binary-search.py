class Solution:
    def rec(self, nums: List[int], target: int, left: int, right: int) -> int:
        if left>right:
            return -1
        mid = (left+right)//2
        if nums[mid]==target:
            return mid
        left_output = self.rec(nums, target, left, mid-1)
        if left_output is not -1 :
            return left_output
        return self.rec(nums, target, mid+1, right)

    def search(self, nums: List[int], target: int) -> int:
        return self.rec(nums, target, 0, len(nums)-1)
        