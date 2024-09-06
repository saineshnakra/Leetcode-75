class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        dicRan = list(magazine)
        
        for i in range(0,len(ransomNote)):
            if ransomNote[i] not in dicRan:
                return False
            else:
                dicRan.remove(ransomNote[i])
        
        return True