# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """

        if not head or not head.next:
            return
        

        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next

        curr = slow.next
        slow.next = None

        stack = deque()
        
        while curr:
            stack.append(curr)
            curr = curr.next

        temp = head

        while stack:
            val1 = stack.pop()
            val2 = temp.next
            temp.next = val1
            val1.next = val2
            temp = val2