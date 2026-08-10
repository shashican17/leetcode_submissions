class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n1 = len(nums1)
        n2 = len(nums2)
        median1 = 0
        median2 = 0
        i1 = 0
        i2 = 0
        for count in range( (n1 + n2) // 2 + 1):
            median2 = median1
            if i1 < n1 and i2 < n2:
                if nums1[i1] > nums2[i2]:
                    median1 = nums2[i2]
                    i2 += 1
                else:
                    median1 = nums1[i1]
                    i1 += 1
            elif i1 < n1:
                median1 = nums1[i1]
                i1 += 1
            else:
                median1 = nums2[i2]
                i2 += 1

        if (n1 + n2) % 2 == 1:
            return float(median1)
        else:
            return (median1 + median2) / 2