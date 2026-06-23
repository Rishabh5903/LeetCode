class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        ans=0
        for i in range(31):
            if(not (right & (1<<i))):
                continue
            else:
                if(((right - (1<<i)) | ((1<<i) -1)) < left):
                    ans+=(1<<i)
        return ans