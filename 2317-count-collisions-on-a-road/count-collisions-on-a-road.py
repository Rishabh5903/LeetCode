class Solution:
    def countCollisions(self, s: str) -> int:
        ans=0
        prev=''
        cnt=0
        for c in s:
            if(c=='R'):
                cnt+=1
                prev='R'
            elif (c=='L'):
                if(prev=='R'):
                    ans+=(cnt+1)
                    prev='S'
                    
                elif(prev=='S'):
                    ans+=1
                cnt=0
            else:
                ans+=cnt
                prev='S'
                cnt=0
        return ans
        