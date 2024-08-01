class Solution:
    def countSeniors(self, details: List[str]) -> int:
        ans=0
        for i in details:
            if(i[11:13]>"60"):
                ans+=1
        return ans
