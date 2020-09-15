# result = [5, 6, 3]
array = [1, 5, 2, 6, 3, 7, 4]
commands = [[2, 5, 3], [4, 4, 1], [1, 7, 3]]


def solution(_array, _commands):
    answer = []
    for command in _commands:
        sub_array = sorted(_array[command[0] - 1:command[1]])
        answer.append(sub_array[command[2] - 1])
    return answer


def solution_unpacking(_array, _commands):
    answer = []
    for command in _commands:
        i, j, k = command
        answer.append(sorted(_array[i - 1: j])[k - 1])
    return answer


def solution_lambda(_array, _commands):
    return list(map(lambda x: sorted(array[x[0] - 1:x[1]])[x[2] - 1], commands))
