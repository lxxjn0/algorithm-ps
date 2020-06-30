/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: dfs/bfs
 * @level: 3
 * @prob_name: 네트워크
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/43162
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool visited[200] = {false};
int computers_size = 0;
int net_count = 0;

void DFS(vector<vector<int>>& computers, int start) {
    if (visited[start] == true) return;

    visited[start] = true;
    for (int i = 0; i < computers_size; i++) {
        if ((start != i) && (computers[start][i])) {
            DFS(computers, i);
        }
    }
}

void ALL_DFS(vector<vector<int>>& computers) {
    for (int i = 0; i < computers_size; i++) {
        if (!visited[i]) {
            ++net_count;
            DFS(computers, i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    computers_size = n;  // computers 2차원 백터의 크기가 N x N 이므로
    ALL_DFS(computers);

    answer = net_count;
    return answer;
}

int main() {
    int n = 3;
    vector<vector<int>> computers = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}};
    cout << solution(n, computers) << endl;
}