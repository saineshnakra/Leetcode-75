# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def middleNode(self, head: Optional[ListNode]) -> Optional[ListNode]:
        curr = fast = head
        if head==None:
            return curr
        while fast!=None and fast.next !=None:
            curr = curr.next
            fast = fast.next
            if fast!=None:
                fast = fast.next
            
        return curr