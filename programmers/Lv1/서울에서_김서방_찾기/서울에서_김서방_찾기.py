# result = "김서방은 1에 있다"

seoul = ["Jane", "Kim"]


def solution(_seoul):
    return "김서방은 " + str(_seoul.index("Kim")) + "에 있다"


def solution_format(_seoul):
    return "김서방은 {}에 있다".format(_seoul.index("Kim"))


print(solution(seoul))
