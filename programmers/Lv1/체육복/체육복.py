# result = 5
n = 5
lost = [2, 4]
reserve = [1, 3, 5]


def solution(_n, _lost, _reserve):
    subtract_lost = set(_lost) - set(_reserve)
    subtract_reserve = set(_reserve) - set(_lost)
    for reserve_index in subtract_reserve:
        if reserve_index - 1 in subtract_lost:
            subtract_lost.remove(reserve_index - 1)
        elif reserve_index + 1 in subtract_lost:
            subtract_lost.remove(reserve_index + 1)
    return _n - len(subtract_lost)


print(solution(n, lost, reserve))
