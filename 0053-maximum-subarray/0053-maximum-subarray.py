class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        global_sum = nums[0]
        current_sum = nums[0]
        for num in nums[1:]:
            current_sum = max(current_sum+num,num)
            global_sum = max(current_sum,global_sum)
        return global_sum
        