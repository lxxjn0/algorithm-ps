# result = [4, 3, 1, 1, 0]
prices = [1, 2, 3, 2, 3]


def solution(_prices):
    answer = [0] * len(_prices)
    stack = []

    for i, price in enumerate(_prices):
        while len(stack) != 0 and stack[len(stack) - 1][1] > price:
            pop_index, pop_price = stack.pop()
            answer[pop_index] = i - pop_index
        stack.append([i, price])

    while len(stack) != 0:
        pop_index, pop_price = stack.pop()
        answer[pop_index] = len(_prices) - pop_index - 1

    return answer


print(solution(prices))
