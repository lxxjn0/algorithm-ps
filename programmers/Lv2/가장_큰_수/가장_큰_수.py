# result = "9534330"
from functools import cmp_to_key

numbers = [3, 30, 34, 5, 9]


def solution(_numbers):
    answer = ''.join(sorted(list(map(str, _numbers)), key=cmp_to_key(comp)))
    return answer


def comp(x, y):
    val_1 = x + y
    val_2 = y + x
    return (int(val_1) < int(val_2)) - (int(val_1) > int(val_2))


print(solution(numbers))
