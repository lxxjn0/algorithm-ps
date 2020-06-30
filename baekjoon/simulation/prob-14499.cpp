/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Simulation
 * @prob_name: 주사위 굴리기
 * @prob_number: 14499
 * @prob_url: https://www.acmicpc.net/problem/14499
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#define E make_pair(0, 1)
#define W make_pair(0, -1)
#define N make_pair(-1, 0)
#define S make_pair(1, 0)
#define ALL_DIR 4
#define ZERO 0
#define BOTTOM 0
#define TOP 5
#define DICE_FACES 6

using namespace std;

typedef pair<int, int> coord;
vector<coord> direction = {E, W, N, S};
vector<vector<int>> play_map;
vector<int> dice = {0, 0, 0, 0, 0, 0};
vector<vector<int>> roll_dice = {
    {3, 1, 0, 5, 4, 2},
    {2, 1, 5, 0, 4, 3},
    {4, 0, 2, 3, 5, 1},
    {1, 5, 2, 3, 0, 4}};
unordered_map<int, int> order_to_dir_map;
vector<int> order_list;
coord dice_pos;
int n = 0;
int m = 0;

coord operator+(coord& c1, coord& c2) {
    return make_pair(c1.first + c2.first, c1.second + c2.second);
}

void MakePlayMap() {
    play_map.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> play_map[i][j];
        }
    }
}

void GetOrderList(int& order_num) {
    for (int i = 0; i < order_num; i++) {
        int order;
        cin >> order;

        order_list.push_back(order);
    }
}

void SetRollDiceOrder() {
    for (int dir = 1; dir <= ALL_DIR; dir++) {
        order_to_dir_map.insert(make_pair(dir, dir - 1));
    }
}

bool IsRange(coord& pos) {
    if (pos.first < 0 || pos.first >= n) {
        return false;
    }
    if (pos.second < 0 || pos.second >= m) {
        return false;
    }
    return true;
}

bool IsPlayMapZero() {
    return play_map[dice_pos.first][dice_pos.second] == ZERO;
}

void SetPlayMap(int set_num) {
    play_map[dice_pos.first][dice_pos.second] = set_num;
}

int GetPlayMap() {
    return play_map[dice_pos.first][dice_pos.second];
}

void RollDiceByOrder(int& dir) {
    vector<int> selected_order_roll = roll_dice[order_to_dir_map[dir]];
    vector<int> new_dice;

    for (int i = 0; i < DICE_FACES; i++) {
        new_dice.push_back(dice[selected_order_roll[i]]);
    }

    dice = new_dice;
}

vector<int> RunDiceRollByOrder() {
    vector<int> answer;

    for (auto& order : order_list) {
        coord next_dice_pos = dice_pos + direction[order_to_dir_map[order]];

        if (!IsRange(next_dice_pos)) {
            continue;
        }
        dice_pos = next_dice_pos;
        RollDiceByOrder(order);
        if (IsPlayMapZero()) {
            SetPlayMap(dice[BOTTOM]);
        } else {
            dice[BOTTOM] = GetPlayMap();
            SetPlayMap(ZERO);
        }

        answer.push_back(dice[TOP]);
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    int y;
    int order_num;
    cin >> n >> m >> x >> y >> order_num;
    dice_pos = make_pair(x, y);

    MakePlayMap();
    GetOrderList(order_num);
    SetRollDiceOrder();
    vector<int> answer = RunDiceRollByOrder();

    for (auto& elem : answer) {
        cout << elem << endl;
    }
}