#!/usr/bin/python3
"""interview questions"""


def isWinner(x, nums):
    """Game decider between Ben and """
    if not nums or x < 1:
        return None
    m = max(nums)
    prime_y = [True for _ in range(max(m + 1, 2))]
    for i in range(2, int(pow(m, 0.5)) + 1):
        if not prime_y[i]:
            continue
        for j in range(i * i, m + 1, i):
            prime_y[j] = False
    prime_y[0] = prime_y[1] = False
    counter = 0
    for k in range(len(prime_y)):
        if prime_y[k]:
            counter += 1
        prime_y[k] = counter
    contester = 0
    for m in nums:
        contester += prime_y[m] % 2 == 1
    if contester * 2 == len(nums):
        return None
    if contester * 2 > len(nums):
        return "Maria"
    return "Ben"
