def solution(_n):
    watermelon = "수박"
    answer = ""
    for i in range(_n // 2):
        answer += watermelon

    if _n % 2 == 1:
        return answer + watermelon[0]
    return answer


def solution_2(_n):
    return "수박" * (_n // 2) + "수" * (_n % 2)
