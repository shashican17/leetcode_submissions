class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        res = float('inf')
        while l <= r:
            mid = l + (r - l) // 2
            res = int(min(res, nums[mid]))
            if nums[l] <= nums[mid] and nums[mid] >= nums[r]:
                l = mid + 1
            else:
                r = mid - 1

        return res