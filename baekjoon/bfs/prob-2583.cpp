/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: BFS
 * @prob_name: 영역 구하기
 * @prob_number: 2583
 * @prob_url: https://www.acmicpc.net/problem/2583
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

#define SPACE 0
#define REC 1
#define CHECK 2
#define N make_pair(-1, 0)
#define E make_pair(0, 1)
#define S make_pair(1, 0)
#define W make_pair(0, -1)

using namespace std;

typedef pair<int, int> coord;
vector<vector<int>> rectangleMap;
vector<coord> direction = {N, E, S, W};
int m = 0;
int n = 0;
int k = 0;

coord operator+(coord& c1, coord& c2) {
    return make_pair(c1.first + c2.first, c1.second + c2.second);
}

void makeRectangleMap() {
    rectangleMap.assign(m, vector<int>(n, 0));

    int a;
    int b;
    int c;
    int d;
    for (int i = 0; i < k; i++) {
        cin >> a >> b >> c >> d;

        for (int j = b; j < d; j++) {
            for (int k = a; k < c; k++) {
                rectangleMap[j][k] = REC;
            }
        }
    }
}

bool isRange(coord& pos) {
    if (pos.first < 0 || pos.first >= m) {
        return false;
    }
    if (pos.second < 0 || pos.second >= n) {
        return false;
    }
    return true;
}

bool isSpace(coord& pos) {
    return rectangleMap[pos.first][pos.second] == SPACE;
}

void checkAllDir(queue<coord>& q, coord& pos) {
    for (auto& dir : direction) {
        coord nextPos = pos + dir;
        if (isRange(nextPos) && isSpace(nextPos)) {
            rectangleMap[nextPos.first][nextPos.second] = CHECK;
            q.push(nextPos);
        }
    }
}

int BFS(coord pos) {
    int spaceCount = 0;
    queue<coord> q;

    q.push(pos);
    rectangleMap[pos.first][pos.second] = CHECK;

    while (!q.empty()) {
        coord curPos = q.front();
        spaceCount++;
        q.pop();
        checkAllDir(q, curPos);
    }
    return spaceCount;
}

void printDividedSpace() {
    vector<int> spaces;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (rectangleMap[i][j] == SPACE) {
                spaces.push_back(BFS(make_pair(i, j)));
            }
        }
    }
    sort(spaces.begin(), spaces.end());

    cout << spaces.size() << endl;
    for (auto& elem : spaces) {
        cout << elem << " ";
    }
}

int main() {
    cin >> m >> n >> k;
    makeRectangleMap();
    printDividedSpace();
}