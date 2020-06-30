/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Simulation
 * @prob_name: 회전하는 큐
 * @prob_number: 1021
 * @prob_url: https://www.acmicpc.net/problem/1021
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> choose;
int head = 0;
int n = 0;
int m = 0;

void makeChoose() {
    choose.assign(m, 0);

    for (int i = 0; i < m; i++) {
        cin >> choose[i];
    }
}

int countOperation(vector<int>& queue, int& idx) {
    int cntOp;
    int curIdx = head;
    int moveCnt = 0;
    int queueSize = queue.size();

    while (true) {
        if (idx == queue[curIdx]) {
            break;
        }

        moveCnt++;
        curIdx = (curIdx + 1) % queueSize;
    }

    cntOp = min(moveCnt, queueSize - moveCnt);

    queue.erase(queue.begin() + curIdx);
    queueSize = queue.size();
    
    if (queueSize != 0) {
        head = curIdx % queue.size();
    } else {
        head = -1;
    }

    return cntOp;
}

int getOperationCount() {
    int answer = 0;
    vector<int> queue;

    for (int i = 1; i <= n; i++) {
        queue.push_back(i);
    }

    for (auto& idx : choose) {
        answer += countOperation(queue, idx);
    }
    return answer;
}

int main() {
    cin >> n >> m;
    makeChoose();

    cout << getOperationCount();
}