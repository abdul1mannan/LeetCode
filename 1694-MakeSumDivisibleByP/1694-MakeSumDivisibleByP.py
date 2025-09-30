# Last updated: 10/1/2025, 12:47:16 AM
class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        n = len(nums)
        
        totalSum=0
        
        for num in nums:
            totalSum = (totalSum+num) % p
            
        if totalSum==0:
            return 0
        
        prefixModMap = {}
        
        prefixModMap[0]=-1
        
        prefixSum = 0
        
        minLen = n
        
        for i in range(0,n):
            prefixSum = (prefixSum+nums[i])%p
            target = (prefixSum-totalSum+p)%p
            
            if target in prefixModMap:
                minLen=min(minLen,i-prefixModMap[target])
                
            prefixModMap[prefixSum]=i
            
        if minLen == n:
            return -1
        else:
            return minLen
  
