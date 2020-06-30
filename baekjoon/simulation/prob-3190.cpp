/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Simulation
 * @prob_name: 뱀
 * @prob_number: 3190
 * @prob_url: https://www.acmicpc.net/problem/3190
 */

#include <iostream>
#include <string>
#include <vector>

#define SPACE 0
#define APPLE 1
#define N 0
#define E 1
#define S 2
#define W 3
#define N_COORD make_pair(-1, 0)
#define E_COORD make_pair(0, 1)
#define S_COORD make_pair(1, 0)
#define W_COORD make_pair(0, -1)

using namespace std;

typedef pair<int, char> order;
typedef pair<int, int> coord;
vector<coord> direction = {N_COORD, E_COORD, S_COORD, W_COORD};
vector<vector<int>> dummyMap;
vector<order> orders;
vector<coord> snake;
int n = 0;
int k = 0;
int l = 0;

coord operator+(coord& c1, coord& c2) {
    return make_pair(c1.first + c2.first, c1.second + c2.second);
}

bool operator==(coord& c1, coord& c2) {
    return c1.first == c2.first && c1.second == c2.second;
}

bool isRange(coord& pos) {
    if (pos.first < 0 || pos.first >= n) {
        return false;
    }
    if (pos.second < 0 || pos.second >= n) {
        return false;
    }
    return true;
}

bool isApple(coord& pos) {
    return dummyMap[pos.first][pos.second] == APPLE;
}

void moveSnake(coord& nextPos) {
    int snakeLen = snake.size();
    snake.insert(snake.begin(), nextPos);
}

bool isCollision() {
    int snakeLen = snake.size();

    for (int i = 1; i < snakeLen; i++) {
        if (snake[0] == snake[i]) {
            return true;
        }
    }
    return false;
}

void makeDummyMap() {
    dummyMap.assign(n, vector<int>(n, SPACE));

    for (int i = 0; i < k; i++) {
        int row;
        int column;
        cin >> row >> column;

        dummyMap[row - 1][column - 1] = APPLE;
    }
}

void makeOrders() {
    orders.assign(l, make_pair(0, '\0'));

    for (int i = 0; i < l; i++) {
        int x;
        char c;
        cin >> x >> c;

        orders[i] = make_pair(x, c);
    }
}

int getNextDir(int& curDir, char& c) {
    if (c == 'L') {
        return (curDir + 3) % 4;
    }
    return (curDir + 1) % 4;
}

int getFinishTime() {
    int dir = E;
    int orderIdx = 0;
    int totalTime = 1;
    coord pos = snake[0];

    while (true) {
        coord nextPos = pos + direction[dir];
        coord tailPos;

        if (!isRange(nextPos)) {
            return totalTime;
        }
        moveSnake(nextPos);

        if (isCollision()) {
            return totalTime;
        }

        if (!isApple(nextPos)) {
            snake.pop_back();
        } else {
            dummyMap[nextPos.first][nextPos.second] = SPACE;
        }

        if (orderIdx < l && orders[orderIdx].first == totalTime) {
            dir = getNextDir(dir, orders[orderIdx].second);
            orderIdx++;
        }

        pos = nextPos;
        totalTime++;
    }
}

int main() {
    cin >> n >> k;
    makeDummyMap();

    cin >> l;
    makeOrders();

    snake.push_back(make_pair(0, 0));
    cout << getFinishTime();
}