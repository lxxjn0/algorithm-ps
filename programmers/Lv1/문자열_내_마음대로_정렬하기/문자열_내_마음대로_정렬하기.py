# result = ["abcd", "abce", "cdx"]
strings = ["abce", "abcd", "cdx"]
n = 2


def solution(_strings, _n):
    return sorted(_strings, key=lambda x: (x[_n], x))


print(solution(strings, n))
