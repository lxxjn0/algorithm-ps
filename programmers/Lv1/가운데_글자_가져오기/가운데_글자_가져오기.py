# result = c
s = "abcde"


def solution(_s):
    s_len = len(_s)
    if s_len % 2 == 0:
        return _s[s_len // 2 - 1:s_len // 2 + 1]
    else:
        return _s[s_len // 2]


print(solution(s))
