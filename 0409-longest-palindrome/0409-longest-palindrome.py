class Solution:
    def longestPalindrome(self, s: str) -> int:
        dic = {}
        for char in s:
            if char not in dic:
                dic[char] = 1
            else:
                dic[char] +=1
        

        flag = 0
        res = 0
        for char in dic:
            if (dic[char]%2)==1:
                flag = 1
                res += dic[char]-1
            else:
                res += dic[char]
            
        return res if flag is 0 else res+1

        