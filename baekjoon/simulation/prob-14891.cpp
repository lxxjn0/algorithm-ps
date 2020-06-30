/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Simulation
 * @prob_name: 톱니바퀴
 * @prob_number: 14891
 * @prob_url: https://www.acmicpc.net/problem/14891
 */

#include <iostream>
#include <string>
#include <vector>

#define HEAD 0
#define REAR 7
#define N 0
#define S 1
#define RIGHT_GEAR 2
#define LEFT_GEAR 6
#define SAME 0
#define RIGHT 1
#define LEFT -1

using namespace std;

vector<int> gear[4];
int k = 0;

void makeGears() {
    for (int i = 0; i < 4; i++) {
        gear[i].assign(8, 0);

        for (int j = 0; j < 8; j++) {
            int tmp;
            scanf("%1d", &tmp);
            gear[i][j] = tmp;
        }
    }
}

bool isSamePole(int gearFirst, int gearSecond) {
    return gear[gearFirst][RIGHT_GEAR] == gear[gearSecond][LEFT_GEAR];
}

int getTurnStatus(bool samePole, int& turnDir) {
    if (turnDir == SAME) {
        return SAME;
    }
    if (samePole) {
        return SAME;
    }
    return -turnDir;
}

vector<int> getTurnDirVec(int turnGearNum, int turnDir) {
    vector<int> turnDirVec(4, 0);
    turnDirVec[turnGearNum] = turnDir;

    int curTurnGearNum = turnGearNum;
    int curTurnDir = turnDir;

    while (true) {
        if (curTurnGearNum > 2) {
            break;
        }
        curTurnDir = getTurnStatus(isSamePole(curTurnGearNum, curTurnGearNum + 1), curTurnDir);
        turnDirVec[++curTurnGearNum] = curTurnDir;
    }

    curTurnGearNum = turnGearNum;
    curTurnDir = turnDir;

    while (true) {
        if (curTurnGearNum < 1) {
            break;
        }
        curTurnDir = getTurnStatus(isSamePole(curTurnGearNum - 1, curTurnGearNum), curTurnDir);
        turnDirVec[--curTurnGearNum] = curTurnDir;
    }
    return turnDirVec;
}

void setGearStatus(int dir, int gearNum) {
    if (dir == SAME) {
        return;
    }
    if (dir == LEFT) {
        int front = gear[gearNum][HEAD];

        gear[gearNum].push_back(front);
        gear[gearNum].erase(gear[gearNum].begin());
        return;
    }
    if (dir == RIGHT) {
        int back = gear[gearNum][REAR];

        gear[gearNum].insert(gear[gearNum].begin(), back);
        gear[gearNum].pop_back();
        return;
    }
}

int calcPoint() {
    int point = 0;

    if (gear[0][HEAD] == S) {
        point += 1;
    }
    if (gear[1][HEAD] == S) {
        point += 2;
    }
    if (gear[2][HEAD] == S) {
        point += 4;
    }
    if (gear[3][HEAD] == S) {
        point += 8;
    }
    return point;
}

int getTotalCount() {
    int gearNum;
    int turnDir;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> gearNum >> turnDir;

        vector<int> turnDirVec = getTurnDirVec(gearNum - 1, turnDir);

        for (int i = 0; i < 4; i++) {
            setGearStatus(turnDirVec[i], i);
        }
    }
    return calcPoint();
}

int main() {
    makeGears();
    cout << getTotalCount();
}