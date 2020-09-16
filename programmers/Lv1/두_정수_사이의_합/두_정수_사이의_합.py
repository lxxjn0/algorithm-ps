# result = 12
a = 3
b = 5


def solution(_a, _b):
    if _a == _b:
        return _a
    elif _a < _b:
        return sum([i for i in range(_a, _b + 1)])
    else:
        return sum([i for i in range(_b, _a + 1)])
