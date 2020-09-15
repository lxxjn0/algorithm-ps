from itertools import combinations

# result = [2, 3, 4, 5, 6, 7]
numbers = [2, 1, 3, 4, 1]


def solution(_numbers):
    answer = list(set([x + y for x, y in combinations(_numbers, 2)]))
    answer.sort()
    return answer


print(solution(numbers))
