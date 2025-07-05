class Solution:
    def findEvenNumbers(self, digits: List[int]) -> List[int]:
        n = len(digits)
        l = set()
        for i in range(0,n):
            if(digits[i]==0):
                continue
            r = digits[i]*100
            for j in range(0,n):
                if(i==j):
                    continue
                r += digits[j]*10
                for k in range(0,n):
                    if(j==k or i==k):
                        continue
                    r += digits[k]
        
                    if(r%2==0):
                        l.add(r)
                    r-=digits[k]
                r-=digits[j]*10
        # l.sort()
        return(list(sorted(l)))

