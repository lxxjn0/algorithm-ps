# result = 4
n = 10


def solution(_n):
    is_prime = [False] * _n
    for i in range(2, _n + 1):
        if not is_prime[i - 1]:
            for j in range(i * 2, _n + 1, i):
                is_prime[j - 1] = True
    return is_prime.count(False) - 1


def solution_set(_n):
    prime = set(range(2, _n))

    for i in range(2, _n + 1):
        if i in prime:
            prime -= set(range(i * 2, _n + 1, i))
    return len(prime)


print(solution(n))

print(solution_set(n))
