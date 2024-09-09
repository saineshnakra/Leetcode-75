# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, root: Optional[TreeNode],dist:int) -> int:
        if root is None:
            return 0
        left = self.helper(root.left,dist)
        right = self.helper(root.right,dist)
        dist = max(dist,right+left)
        return 1 + max(left, right)
    
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        return self.helper(root, 0)

        