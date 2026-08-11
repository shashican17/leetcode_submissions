"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        newList = {}
        newList[None] = None

        temp = head

        while temp:
            newNode = Node(temp.val)
            newList[temp] = newNode
            temp = temp.next

        temp = head

        while temp:
            newNode = newList[temp]
            newNode.next = newList[temp.next]
            newNode.random = newList[temp.random]
            temp = temp.next
        
        return newList[head]