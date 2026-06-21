class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ans=[]
        n = len(intervals)
        intervals.sort()
        ans.append(intervals[0])
        for i in range(1, n):
            ans.append(intervals[i])
            while(len(ans)>1 and ans[-1][0]<=ans[-2][1]):
                ans[-2][0]=min(ans[-2][0], ans[-1][0])
                ans[-2][1]=max(ans[-2][1], ans[-1][1])
                ans.pop()
        return ans