class Solution:
    def addBinary(self, a: str, b: str) -> str:
        temp1 = a[::-1]
        temp2 = b[::-1]
        res = ""
        carry = 0
        for i in range(min(len(temp1), len(temp2))):
            if temp1[i] == '1' and temp2[i] == '1':
                if carry == 1:
                    res += '1'
                else:
                    res += '0'
                carry = 1
            elif temp1[i] == '1' and temp2[i] == '0' or temp2[i] == '1' and temp1[i] == '0':
                if carry == 1:
                    res += '0'
                else:
                    res += '1'
            elif temp1[i] == '0' and temp2[i] == '0':
                if carry == 1:
                    res += '1'
                    carry = 0
                else:
                    res += '0'

        # Add the remaining digits of the longer string
        remainder = temp1[len(temp2):] if len(temp1) > len(temp2) else temp2[len(temp1):]
        for char in remainder:
            if char == '1':
                if carry == 1:
                    res += '0'
                else:
                    res += '1'
            else:
                if carry == 1:
                    res += '1'
                    carry = 0
                else:
                    res += '0'

        # If there's still a carry left, append '1'
        if carry == 1:
            res += '1'
        
        return res[::-1]
