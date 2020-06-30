/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Simulation
 * @prob_name: 체스판 다시 칠하기
 * @prob_number: 1018
 * @prob_url: https://www.acmicpc.net/problem/1018
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define BOARD_SIZE 8

using namespace std;

typedef pair<int, int> coord;
vector<vector<char>> chess_board;
vector<vector<char>> black_start_board;
vector<vector<char>> white_start_board;
int n = 0;
int m = 0;

coord operator+(coord& c1, coord& c2) {
    return make_pair(c1.first + c2.first, c1.second + c2.second);
}

void MakeCompareChessBoard() {
    black_start_board.assign(BOARD_SIZE, vector<char>(BOARD_SIZE, ' '));
    white_start_board.assign(BOARD_SIZE, vector<char>(BOARD_SIZE, ' '));

    char color[2] = {'W', 'B'};
    int black_row_color = 0;
    int white_row_color = 1;

    for (int i = 0; i < BOARD_SIZE; i++) {
        black_row_color = !black_row_color;
        white_row_color = !white_row_color;

        for (int j = 0; j < BOARD_SIZE; j++) {
            black_start_board[i][j] = j % 2 == 0 ? color[black_row_color] : color[!black_row_color];
            white_start_board[i][j] = j % 2 == 0 ? color[white_row_color] : color[!white_row_color];
        }
    }
}

void MakeChessBoard() {
    char space;
    chess_board.assign(n, vector<char>(m, ' '));

    for (int i = 0; i < n; i++) {
        scanf("%c", &space);
        for (int j = 0; j < m; j++) {
            scanf("%c", &chess_board[i][j]);
        }
    }
}

bool IsRange(coord& left_upper) {
    if (left_upper.first + BOARD_SIZE - 1 >= n) {
        return false;
    }
    if (left_upper.second + BOARD_SIZE - 1 >= m) {
        return false;
    }
    return true;
}

char GetCurPosColor(coord& pos) {
    return chess_board[pos.first][pos.second];
}

int CalcPaintWork(coord& left_upper) {
    int black_board_paint = 0;
    int white_board_paint = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            coord cur_board_pos = make_pair(left_upper.first + i, left_upper.second + j);

            if (GetCurPosColor(cur_board_pos) != black_start_board[i][j]) {
                black_board_paint++;
            }
            if (GetCurPosColor(cur_board_pos) != white_start_board[i][j]) {
                white_board_paint++;
            }
        }
    }
    return min(black_board_paint, white_board_paint);
}

int GetMinPaintWork() {
    int answer = BOARD_SIZE * BOARD_SIZE;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            coord left_upper = make_pair(i, j);

            if (IsRange(left_upper)) {
                int paint_count = CalcPaintWork(left_upper);
                answer = answer > paint_count ? paint_count : answer;
            }
        }
    }
    return answer;
}

int main() {
    cin >> n >> m;

    MakeCompareChessBoard();
    MakeChessBoard();

    cout << GetMinPaintWork() << endl;
}