class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        res1 = []
        for char in s:
            if char != '#':
                res1.append(char)
            else:
                if len(res1)!=0:
                    res1.pop()
        res2 = []
        for char in t:
            if char != '#':
                res2.append(char)
            else:
                if len(res2)!=0:
                    res2.pop()

        return res1==res2
     
        