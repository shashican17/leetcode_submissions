class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n1 = len(nums1)
        n2 = len(nums2)
        i , j = 0, 0
        median1 , median2 = 0, 0

        for count in range( (n1 + n2) // 2 + 1 ):
            median2 = median1
            if i < n1 and j < n2:
                if nums1[i] > nums2[j]:
                    median1 = nums2[j]
                    j += 1
                else:
                    median1 = nums1[i]
                    i += 1
            elif i < n1:
                median1 = nums1[i]
                i += 1
            else:
                median1 = nums2[j]
                j += 1
        
        if (n1 + n2) % 2 == 1:
            return median1
        else:
            return (median1 + median2) / 2