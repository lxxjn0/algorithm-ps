from math import ceil

# result = [1, 3, 2]
progresses = [95, 90, 99, 99, 80, 99]
speeds = [1, 1, 1, 1, 1, 1]


def solution(_progresses, _speeds):
    answer = []
    zipped_list = [[_progresses[i], _speeds[i]] for i in range(len(_progresses))]

    while zipped_list:
        days = ceil((100 - zipped_list[0][0]) / zipped_list[0][1])

        count = 0
        for i in range(len(zipped_list)):
            if (zipped_list[i][0] + zipped_list[i][1] * days) >= 100:
                count += 1
            else:
                break
        for i in range(count, len(zipped_list)):
            zipped_list[i][0] += (zipped_list[i][1] * days)
        answer.append(count)
        zipped_list = zipped_list[count:]
    return answer


def solution_queue(_progress, _speeds):
    answer = []

    for p, s in zip(_progress, _speeds):
        if not answer or answer[-1][0] < ceil((100 - p) / s):
            answer.append([ceil((100 - p) / s), 1])
        else:
            answer[-1][1] += 1
    return [i[1] for i in answer]


print(solution(progresses, speeds))

print(solution_queue(progresses, speeds))
