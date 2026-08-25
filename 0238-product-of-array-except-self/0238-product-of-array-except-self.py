class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        leftProduct = [1] * n
        rightProduct = [1] * n
        res = [1] * n

        i = 1
        while i < n:
            leftProduct[i] = leftProduct[i-1] * nums[i-1]
            i += 1
        
        i = n-2
        while i >= 0:
            rightProduct[i] = rightProduct[i+1] * nums[i+1]
            i -= 1
        
        i = 0
        while i < n:
            res[i] = leftProduct[i] * rightProduct[i]
            i += 1
        return res