class Solution:
    def isPalindrome(self, x: int) -> bool:
        if(x<0):
            return(False)
        else:
            n = 0
            for i in range(0,100):
                if(x//pow(10,i)==0):
                    n = i
                    break
            for i in range(1,(n//2)+1):
                if(((x//pow(10,i-1))%10) != ((x//pow(10,n-i))%10)):
                    return(False)
        return(True)
