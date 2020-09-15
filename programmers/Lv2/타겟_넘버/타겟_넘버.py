# result = 5
numbers = [1, 1, 1, 1, 1]
target = 3
answer = 0


def recursive(index, _target, _numbers):
    global answer
    if index == -1:
        if _target == 0:
            answer += 1
        return
    recursive(index - 1, _target - _numbers[index], _numbers)
    recursive(index - 1, _target + _numbers[index], _numbers)


def solution(_numbers, _target):
    global answer
    recursive(len(_numbers) - 1, _target, _numbers)
    return answer


def solution_dfs(_numbers, _target):
    if not _numbers and _target == 0:
        return 1
    elif not _numbers:
        return 0
    else:
        return solution(_numbers[1:], _target - _numbers[0]) + solution(_numbers[1:], _target + _numbers[0])
