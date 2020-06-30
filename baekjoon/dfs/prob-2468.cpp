/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: DFS
 * @prob_name: 안전 영역
 * @prob_number: 2468
 * @prob_url: https://www.acmicpc.net/problem/2468
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define SAFE 0
#define SINK 1
#define CHECK 2
#define N make_pair(-1, 0)
#define E make_pair(0, 1)
#define S make_pair(1, 0)
#define W make_pair(0, -1)

using namespace std;

typedef pair<int, int> coord;
vector<vector<int>> heightMap;
vector<vector<int>> sinkMap;
vector<coord> direction = {N, E, S, W};
int n = 0;
int maxHeight = 0;
int maxSpaceNum = 1;

coord operator+(coord& c1, coord& c2) {
    return make_pair(c1.first + c2.first, c1.second + c2.second);
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

void makeMap() {
    heightMap.assign(n, vector<int>(n, 0));
    sinkMap.assign(n, vector<int>(n, SAFE));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> heightMap[i][j];
        }

        int curMaxheight = *max_element(heightMap[i].begin(), heightMap[i].end());

        if (maxHeight < curMaxheight) {
            maxHeight = curMaxheight;
        }
    }
}

void checkSinkSpace(vector<vector<int>>& curSinkMap, int sinkHeight) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (heightMap[i][j] <= sinkHeight) {
                curSinkMap[i][j] = SINK;
            }
        }
    }
}

void DFS(vector<vector<int>>& curSinkMap, coord& pos) {
    for (auto& dir : direction) {
        coord nextPos = pos + dir;
        if (isRange(nextPos) && curSinkMap[nextPos.first][nextPos.second] == SAFE) {
            curSinkMap[nextPos.first][nextPos.second] = CHECK;
            DFS(curSinkMap, nextPos);
        }
    }
}

int getSafeSpaceNum(vector<vector<int>>& curSinkMap) {
    int safeSpaceCount = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (curSinkMap[i][j] == SAFE) {
                coord pos = make_pair(i, j);
                DFS(curSinkMap, pos);
                safeSpaceCount++;
            }
        }
    }
    return safeSpaceCount;
}

int getMaxSafeSpaceNum() {
    for (int i = 1; i < maxHeight; i++) {
        vector<vector<int>> curSinkMap = sinkMap;
        checkSinkSpace(curSinkMap, i);

        int curSafeSpaceNum = getSafeSpaceNum(curSinkMap);

        if (curSafeSpaceNum > maxSpaceNum) {
            maxSpaceNum = curSafeSpaceNum;
        }
    }
    return maxSpaceNum;
}

int main() {
    cin >> n;
    makeMap();

    cout << getMaxSafeSpaceNum();
}