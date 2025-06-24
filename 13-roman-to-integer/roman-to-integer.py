class Solution:
    def romanToInt(self, s: str) -> int:
        map={}
        map['I']=1
        map['V']=5
        map['X']=10
        map['L']=50
        map['C']=100
        map['D']=500
        map['M']=1000
        map['IV']=4
        map['IX']=9
        map['XL']=40
        map['XC']=90
        map['CD']=400
        map['CM']=900
        ans = 0
        i=0
        while(i<len(s)):
            if(i<len(s)-1 and (s[i]+s[i+1] in map)):
                ans+= map[s[i]+s[i+1]]
                i+= 2
            else:
                ans+= map[s[i]]
                i+=1
        return(ans)
        
        
