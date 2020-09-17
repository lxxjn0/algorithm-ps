from collections import Counter

# result = true
s = "pPoooyY"


def solution(_s):
    lower_s = _s.lower()
    count_s = Counter(lower_s)
    return count_s.get("y") == count_s.get("p")


def solution_list_count(_s):
    return _s.lower().count('p') == _s.lower().count('y')


print(solution(s))
