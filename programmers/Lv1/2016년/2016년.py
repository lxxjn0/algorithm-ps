days = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
day_of_week = ["THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"]


def solution(_a, _b):
    if _a == 1:
        return day_of_week[_b % 7]
    else:
        return day_of_week[(sum(days[:_a - 1]) + _b) % 7]


print(solution(2, 1))
