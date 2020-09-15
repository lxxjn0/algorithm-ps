# result = [1, 3, 0, 1]
arr = [1, 1, 3, 3, 0, 1, 1]


def solution(_arr):
    answer = []

    for i in _arr:
        if not answer:
            answer.append(i)
        elif answer[-1] != i:
            answer.append(i)
    return answer


def solution_slice(_arr):
    answer = []

    for i in _arr:
        if answer[-1:] != [i]:
            answer.append(i)
    return answer


print(solution_slice(arr))
