# result = [1, 2, 3, 36]
arr = [2, 36, 1, 3]
divisor = 1


def solution(_arr, _divisor):
    dividable = [i for i in _arr if i % _divisor == 0]
    if not dividable:
        return [-1]
    return sorted(dividable)


def solution_use_or(_arr, _divisor):
    return sorted([i for i in _arr if i % _divisor == 0]) or [-1]
