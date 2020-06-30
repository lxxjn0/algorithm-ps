/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: DFS
 * @prob_name: 경로 찾기
 * @prob_number: 11403
 * @prob_url: https://www.acmicpc.net/problem/11403
 */

#include <iostream>
#include <list>
#include <string>
#include <vector>

#define NOT_LINK 0
#define LINK 1

using namespace std;

vector<vector<int>> possibleRoute;
list<int>* adjustList;
int n;

void makeAdjustList() {
    possibleRoute.assign(n, vector<int>(n, NOT_LINK));
    adjustList = new list<int>[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int temp;
            cin >> temp;

            if (temp == LINK) {
                adjustList[i].push_back(j);
            }
        }
    }
}

bool isPossibleRoute(int& start, int& end) {
    return possibleRoute[start][end] == LINK;
}

void findRouteDFS(int start, int via) {
    list<int>::iterator it;

    for (it = adjustList[via].begin(); it != adjustList[via].end(); it++) {
        if (!isPossibleRoute(start, *it)) {
            possibleRoute[start][*it] = LINK;
            findRouteDFS(start, *it);
        }
    }
}

void findAllRoute() {
    for (int i = 0; i < n; i++) {
        findRouteDFS(i, i);
    }
}

void printPossibleRoute() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << possibleRoute[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> n;

    makeAdjustList();
    findAllRoute();
    printPossibleRoute();
}