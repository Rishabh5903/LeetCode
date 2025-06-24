class Solution:
    def findKDistantIndices(self, nums: List[int], key: int, k: int) -> List[int]:
        n = len(nums)
        l=[]
        l1=[]
        for i in range(0,n):
            if(nums[i]==key):
                l.append(i)
        for i in range(0,n):
            for j in l:
                if(abs(i-j)<=k):
                    l1.append(i)
                    break
        return(l1)
                    
