/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: BFS
 * @prob_name: 연결 요소의 개수
 * @prob_number: 11724
 * @prob_url: https://www.acmicpc.net/problem/11724
 */

#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>

using namespace std;

list<int>* adjustList;
vector<bool> visit;

void makeAdjustList(int& u, int& v) {
    adjustList = new list<int>[u];
    visit.assign(u, false);

    for (int i = 0; i < v; i++) {
        int prev;
        int next;
        cin >> prev >> next;
        adjustList[prev - 1].push_back(next - 1);
        adjustList[next - 1].push_back(prev - 1);
    }
}

void DFS(int nodeNum) {
    list<int>::iterator list_it;
    visit[nodeNum] = true;

    for (list_it = adjustList[nodeNum].begin(); list_it != adjustList[nodeNum].end(); list_it++) {
        if (!visit[*list_it]) {
            DFS(*list_it);
        }
    }
}

void BFS(int& nodeNum) {
    queue<int> q;
    q.push(nodeNum);

    while (!q.empty()) {
        list<int>::iterator list_it;
        int curFront = q.front();
        q.pop();

        if (!visit[curFront]) {
            visit[curFront] = true;

            for (list_it = adjustList[curFront].begin(); list_it != adjustList[curFront].end(); list_it++) {
                if (!visit[*list_it]) {
                    q.push(*list_it);
                }
            }
        }
    }
}

int getConnectCompNum(int& u, int& v) {
    int countComp = 0;

    for (int i = 0; i < u; i++) {
        if (!visit[i]) {
            // DFS(i);
            BFS(i);
            countComp++;
        }
    }
    return countComp;
}

int main() {
    int u;
    int v;
    cin >> u >> v;

    makeAdjustList(u, v);
    cout << getConnectCompNum(u, v) << endl;
}