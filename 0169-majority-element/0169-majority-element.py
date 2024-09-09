class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 1
        curr = nums[0]

        for num in nums[1:]:
            if nums==curr:
                count+=1
            else:
                count-=1
            if count==0:
                curr = num
                count = 1
        return curr
        