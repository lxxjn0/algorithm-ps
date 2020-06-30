/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: 서머코딩/윈터코딩(2018)
 * @level: 3
 * @prob_name: 배달
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/12978
 */

#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<int> possible;
int road_map[51][51] = {0};
bool visited[51] = {false};

int N_ = 0;
int K_ = 0;

void DFS(int pos, int cost) {
    if (cost > K_) {
        return;
    } else {
        possible.insert(pos);
        visited[pos];
    }

    for (int i = 1; i <= N_; i++) {
        int val = road_map[pos][i];
        if (val != 0) {
            if (!visited[i]) {
                DFS(i, cost + val);
            }
        }
    }
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    N_ = N;
    K_ = K;

    for (auto elem : road) {
        int first = road_map[elem[0]][elem[1]];
        int second = road_map[elem[1]][elem[0]];
        int val = elem[2];
        if (first != 0) {
            if (first > val) {
                road_map[elem[0]][elem[1]] = val;
            }
        } else {
            road_map[elem[0]][elem[1]] = val;
        }

        if (second != 0) {
            if (second > val) {
                road_map[elem[1]][elem[0]] = val;
            }
        } else {
            road_map[elem[1]][elem[0]] = val;
        }
    }

    possible.insert(1);
    visited[1] = true;
    DFS(1, 0);
    answer = possible.size();
    return answer;
}

int main() {
    int N = 5;
    int K = 3;
    vector<vector<int>> road = {
        {1, 2, 1},
        {2, 3, 3},
        {5, 2, 2},
        {1, 4, 2},
        {5, 3, 1},
        {5, 4, 2}};
    cout << solution(N, road, K) << endl;
}