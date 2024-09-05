# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rec(self, root: Optional[TreeNode]):
        if root is None:
            return None
        self.rec(root.left)
        self.rec(root.right)
        temp_root = root.left
        root.left = root.right
        root.right = temp_root
    
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        ret_root = root
        self.rec(root)
        return ret_root
        