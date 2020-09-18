# result = 'gfedcbZ'
s = 'Zbcdefg'


def solution(_s):
    return ''.join(sorted(_s, reverse=True))


print(solution(s))
