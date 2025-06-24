class Solution:
    def romanToInt(self, s: str) -> int:

        val = {
            'I':1,
            'V':5,
            'X':10,
            'L':50,
            'C':100,
            'D':500,
            'M':1000
        }
        
        value=0
        max_so_far=0
        for i in range(len(s)-1,-1,-1):
            el = s[i]
            digit = val[el]
            max_so_far = max(digit,max_so_far)
            if digit<max_so_far:
                value-=digit
            else:
                value+=digit
                
        return value