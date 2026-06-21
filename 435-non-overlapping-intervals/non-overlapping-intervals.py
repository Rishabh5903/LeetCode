class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        l = []
        ans=0
        intervals.sort()
        l.append(intervals[0])
        for i in range(1, len(intervals)):
            if(intervals[i][0] >= l[-1][1]):
                l.append(intervals[i])
            else:
                ans+=1
                l[-1][1] = min(l[-1][1], intervals[i][1])
        return ans