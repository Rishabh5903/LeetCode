class Solution:
    def findLucky(self, arr: List[int]) -> int:
        l = [0]*501
        n = len(arr)
        x = -1
        for i in range(n):
            l[arr[i]] += 1
        for i in range(1,501):
            if(l[i]==i):
                x = max(l[i],x)
        return(x)