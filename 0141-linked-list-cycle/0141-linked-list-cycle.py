# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        curr = fast = head
        while curr is not None or (curr is not fast and curr is not head):
            curr = curr.next
            fast = fast.next
            if fast is None or fast.next is None:
                return False
            fast = fast.next
            if fast is curr :
                return True
        return False