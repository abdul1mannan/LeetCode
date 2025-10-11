class Solution:
    def getLeastFrequentDigit(self, n: int) -> int:
        s=str(n)

        freq={}
        for ch in s:
            digit=int(ch)
            freq[digit]=freq.get(digit,0)+1

        least_freq=min(freq.items(),key=lambda x:(x[1],x[0]))[0]

        return least_freq
        