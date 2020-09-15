# result = 4
board = [[0, 0, 0, 0, 0], [0, 0, 1, 0, 3], [0, 2, 5, 0, 1], [4, 2, 4, 4, 2], [3, 5, 1, 3, 1]]
moves = [1, 5, 3, 5, 1, 2, 1, 4]


def solution(_board, _moves):
    answer = 0

    _board = list(zip(*_board))
    _moves = [i - 1 for i in _moves]
    stack = []
    board_index = [0] * len(_board)

    for move in _moves:
        for i in range(board_index[move], len(_board)):
            current = _board[move][i]
            if current != 0:
                board_index[move] = i + 1
                stack.append(current)

                if len(stack) > 1 and current == stack[-2]:
                    stack = stack[:-2]
                    answer += 2
                break
    return answer


print(solution(board, moves))
