#!/usr/bin/python3
"""interview questions"""


def isWinner(x, nums):
    """Game decider between Ben and """
    if x < len(nums) or x < 1:
        return None
    m = max(nums)
    prime = [True for _ in range(max(m + 1, 2))]
    for i in range(2, int(pow(m, 0.5)) + 1):
        if not prime[i]:
            continue
        for j in range(i * i, m + 1, i):
            prime[j] = False
    prime[0] = prime[1] = False
    x = 0
    for k in range(len(prime)):
        if prime[k]:
            k += 1
        prime[i] = k
    contester_m = 0
    for n in nums:
        contester_m += prime[n] % 2 == 1
    if contester_m * 2 == len(nums):
        return None
    if contester_m * 2 < len(nums):
        return "Ben"
    return "Maria"
