class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        i = len(nums)//2
        return nums[i]
        