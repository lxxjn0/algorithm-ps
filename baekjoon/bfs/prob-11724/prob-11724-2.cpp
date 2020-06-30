/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: BFS
 * @prob_name: 연결 요소의 개수
 * @prob_number: 11724
 * @prob_url: https://www.acmicpc.net/problem/11724
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

list<int>* adjustList;
vector<int> u_root;
vector<int> u_rank;

void makeSet(int& u) {
    u_root.assign(u, 0);
    u_rank.assign(u, 0);

    for (int i = 0; i < u; i++) {
        u_root[i] = i;
        u_rank[i] = 0;
    }
}

int findRoot(int x) {
    if (u_root[x] == x) {
        return x;
    } else {
        return u_root[x] = findRoot(u_root[x]);
    }
}

void unionSet(int x, int y) {
    x = findRoot(x);
    y = findRoot(y);

    if (x == y) {
        return;
    } else {
        if (u_rank[x] < u_rank[y]) {
            u_root[x] = y;
        } else if (u_rank[x] > u_rank[y]) {
            u_root[y] = x;
        } else {
            u_root[y] = x;
            u_rank[x]++;
        }
    }
}

void makeAdjustList(int& u, int& v) {
    adjustList = new list<int>[u];
    makeSet(u);

    for (int i = 0; i < v; i++) {
        int prev;
        int next;
        cin >> prev >> next;

        adjustList[prev - 1].push_back(next - 1);
        adjustList[next - 1].push_back(prev - 1);
    }
}

int getConnectCompNum(int u) {
    int countComp = 0;

    for (int i = 0; i < u; i++) {
        list<int>::iterator list_it;

        for (list_it = adjustList[i].begin(); list_it != adjustList[i].end(); list_it++) {
            unionSet(i, *list_it);
        }
    }

    for (int i = 0; i < u; i++) {
        if (u_root[i] == i) {
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
    cout << getConnectCompNum(u) << endl;
}