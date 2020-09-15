/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: graph
 * @level: 3
 * @prob_name: 가장 먼 노드
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/49189
 */

#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

queue<pair<int, int>> q;
int cnt[20001] = {0};
bool visited[20001] = {false};

int BFS(vector<vector<int>>& edge) {
    int edge_size = edge.size();
    int max_dep = 0;
    q.push(make_pair(1, 0));  // node : 1, depth : 1인 pair 삽입
    visited[1] = true;
    cnt[0]++;

    int node = 0, depth = 0;
    while (!q.empty()) {
        tie(node, depth) = q.front();
        q.pop();
        for (int i = 0; i < edge_size; i++) {
            if (node == edge[i][0]) {
                if (!visited[edge[i][1]]) {
                    visited[edge[i][1]] = true;
                    q.push(make_pair(edge[i][1], depth + 1));
                    cnt[depth + 1]++;
                    if (max_dep < depth + 1) max_dep = depth + 1;
                }
            } else if (node == edge[i][1]) {
                if (!visited[edge[i][0]]) {
                    visited[edge[i][0]] = true;
                    q.push(make_pair(edge[i][0], depth + 1));
                    cnt[depth + 1]++;
                    if (max_dep < depth + 1) max_dep = depth + 1;
                }
            }
        }
    }
    return cnt[max_dep];
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    answer = BFS(edge);
    return answer;
}

int main() {
    int n = 6;
    vector<vector<int>> edge = {
        {3, 6},
        {4, 3},
        {3, 2},
        {1, 3},
        {1, 2},
        {2, 4},
        {5, 2}};
    cout << solution(n, edge) << endl;
}