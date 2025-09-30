# Last updated: 10/1/2025, 12:47:23 AM
class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        remainderCount =  defaultdict(int)
        
        for num in arr:
            remainder = ((num%k)+k)%k
            remainderCount[remainder] +=1
            
        for i in range((k//2)+1):
            if i ==0:
                if remainderCount[0]%2!=0 :
                    return False
            else:
                if remainderCount[i]!=remainderCount[k-i]:
                    return False
                
        return True
        