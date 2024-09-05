class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        hashmap = {}
        for char in s:
            if char not in hashmap:
                hashmap[char] = 1
            else:
                hashmap[char] +=1
        for char in t:
            if char not in hashmap:
                return False
            hashmap[char]-=1
            if hashmap[char]<=0:
                del hashmap[char]

        return not hashmap
        
        