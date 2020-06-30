/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: BFS
 * @prob_name: 토마토
 * @prob_number: 7576
 * @prob_url: https://www.acmicpc.net/problem/7576
 */

#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

#define EMPTY -1
#define NOT_RIPEN 0
#define RIPEN 1
#define UP make_pair(-1, 0)
#define DOWN make_pair(1, 0)
#define LEFT make_pair(0, -1)
#define RIGHT make_pair(0, 1)

using namespace std;

typedef pair<int, int> coord;
typedef pair<coord, int> ripenDay;
vector<vector<int>> tomatoBox;
vector<coord> notRipens;
vector<coord> ripens;
vector<coord> directions = {UP, DOWN, LEFT, RIGHT};
int n;
int m;

coord operator+(coord& c1, coord& c2) {
    return make_pair(c1.first + c2.first, c1.second + c2.second);
}

void makeTomatoBox() {
    tomatoBox.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;

            tomatoBox[i][j] = temp;
            if (temp == NOT_RIPEN) {
                notRipens.push_back(make_pair(i, j));
            }
            if (temp == RIPEN) {
                ripens.push_back(make_pair(i, j));
            }
        }
    }
}

bool isRange(coord& pos) {
    if (pos.first < 0 || pos.first >= n) {
        return false;
    }
    if (pos.second < 0 || pos.second >= m) {
        return false;
    }
    return true;
}

bool isNotRipen(coord& pos) {
    return tomatoBox[pos.first][pos.second] == NOT_RIPEN;
}

void setTomatoBox(int status, coord& pos) {
    tomatoBox[pos.first][pos.second] = status;
}

int ripeAllDirection(queue<ripenDay>& q, coord& pos, int& curRipenDay) {
    int ripenCount = 0;

    for (auto& dir : directions) {
        coord nextPos = pos + dir;

        if (isRange(nextPos) && isNotRipen(nextPos)) {
            setTomatoBox(RIPEN, nextPos);
            q.push(make_pair(nextPos, curRipenDay + 1));
            ripenCount++;
        }
    }
    return ripenCount;
}

int getTotalRipenDay() {
    int notRipensNum = notRipens.size();
    int ripensSize = ripens.size();

    queue<ripenDay> q;
    coord pos;
    int curRipenDay = 0;

    for (int i = 0; i < ripensSize; i++) {
        q.push(make_pair(ripens[i], 0));
    }

    while (!q.empty()) {
        tie(pos, curRipenDay) = q.front();
        q.pop();

        notRipensNum -= ripeAllDirection(q, pos, curRipenDay);
    }

    if (notRipensNum != 0) {
        return -1;
    }
    return curRipenDay;
}

int main() {
    cin >> m >> n;

    makeTomatoBox();
    cout << getTotalRipenDay() << endl;
}