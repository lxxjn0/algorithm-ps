# result = false
s = 'a234'


def solution(_s):
    if len(_s) != 4 and len(_s) != 6:
        return False
    for i in _s:
        if 'a' <= i <= 'z':
            return False
    return True


def solution_is_digit(_s):
    return _s.isdigit() and len(_s) in (4, 6)


print(solution(s))
