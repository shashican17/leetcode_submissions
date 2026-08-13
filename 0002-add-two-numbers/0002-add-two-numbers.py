# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        res = temp = ListNode()
        carry = 0

        while l1 and l2:
            value = l1.val + l2.val + carry            
            newNode = ListNode()
            newNode.val = value % 10
            carry = value // 10
            l1 = l1.next
            l2 = l2.next
            temp.next = newNode
            temp = temp.next
        
        while l1:
            value = l1.val + carry
            newNode = ListNode()
            newNode.val = value % 10
            carry = value // 10
            l1 = l1.next
            temp.next = newNode
            temp = temp.next
        
        while l2:
            value = l2.val + carry
            newNode = ListNode()
            newNode.val = value % 10
            carry = value // 10
            l2 = l2.next
            temp.next = newNode
            temp = temp.next
        
        if carry != 0:
            newNode = ListNode()
            newNode.val = carry
            temp.next = newNode
            temp = temp.next
        
        return res.next