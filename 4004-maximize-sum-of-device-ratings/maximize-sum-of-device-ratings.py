class Solution:
    def maxRatings(self, units: List[List[int]]) -> int:
        
        for l in units:
            l.sort()
        units.sort()
        ans=0
        mino=100001
        for l in units:
            if(len(l)>=2):
                ans+=l[1]
                mino=min(mino,l[1])
            else:
                ans+=l[0]
                mino=min(mino,l[0])
        ans-=mino
        ans+=units[0][0]
        return ans