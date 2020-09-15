/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: graph
 * @level: 3
 * @prob_name: 순위
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/49191
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> results_;

void BFS_UP(set<int>& nodes, int source, bool* visited) {
    queue<int> q;
    int re_size = results_.size();

    q.push(source);

    int pos = 0;
    while (!q.empty()) {
        pos = q.front();
        q.pop();
        for (int i = 0; i < re_size; i++) {
            if (results_[i][1] == pos) {
                if (!visited[results_[i][0]]) {
                    nodes.insert(results_[i][0]);
                    q.push(results_[i][0]);
                    visited[results_[i][0]] = true;
                }
            }
        }
    }
}

void BFS_DOWN(set<int>& nodes, int source, bool* visited) {
    queue<int> q;
    int re_size = results_.size();

    q.push(source);

    int pos = 0;
    while (!q.empty()) {
        pos = q.front();
        q.pop();
        for (int i = 0; i < re_size; i++) {
            if (results_[i][0] == pos) {
                if (!visited[results_[i][1]]) {
                    nodes.insert(results_[i][1]);
                    q.push(results_[i][1]);
                    visited[results_[i][1]] = true;
                }
            }
        }
    }
}

int BFS(int n, int source) {
    set<int> nodes;
    bool visited[101] = {false};
    BFS_UP(nodes, source, visited);
    BFS_DOWN(nodes, source, visited);

    return nodes.size();
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    results_ = results;

    for (int i = 1; i <= n; i++) {
        int r_check = BFS(n, i);
        if (r_check == n - 1) answer++;
    }

    return answer;
}

int main() {
    int n = 5;
    vector<vector<int>> results = {
        {4, 3},
        {4, 2},
        {3, 2},
        {1, 2},
        {2, 5}};
    cout << solution(n, results) << endl;
}