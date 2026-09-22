class Solution:
    def longestPalindrome(self, s: str) -> int:
        count = {}
        
        for ch in s:
            count[ch] = count.get(ch, 0) + 1
        
        ans = 0
        odd = False
        
        for freq in count.values():
            ans += (freq // 2) * 2
            if freq % 2 == 1:
                odd = True
        
        if odd:
            ans += 1
        
        return ans