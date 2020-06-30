/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: 서머코딩/윈터코딩(2018)
 * @level: 3
 * @prob_name: 배달
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/12978
 */

#include <iostream>
#include <queue>
#include <set>
#include <vector>

#define INF 1e9

using namespace std;

typedef pair<int, int> edge;
vector<vector<int>> road_map(51, vector<int>(51, INF));

int N_ = 0;
int K_ = 0;

struct compare {
    bool operator()(edge a, edge b) {
        return a.second > b.second;
    }
};

int djikstra(int start) {
    priority_queue<edge, vector<edge>, compare> pq;
    pq.push(make_pair(start, 0));

    vector<int> distance(N_ + 1, INF);
    distance[start] = 0;

    while (!pq.empty()) {
        edge v = pq.top();
        pq.pop();

        for (int u = 1; u <= N_; u++) {
            if (road_map[v.first][u] != INF) {
                int minDist = distance[v.first] + road_map[v.first][u];
                if (distance[u] > minDist) {
                    distance[u] = minDist;
                    pq.push(make_pair(u, road_map[v.first][u]));
                }
            }
        }
    }

    int count = 0;
    for (auto elem : distance) {
        if (elem <= K_) {
            count++;
        }
    }
    return count;
}

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    N_ = N;
    K_ = K;

    for (auto elem : road) {
        int first = road_map[elem[0]][elem[1]];
        int second = road_map[elem[1]][elem[0]];
        int val = elem[2];

        if (first > val) {
            road_map[elem[0]][elem[1]] = val;
        }

        if (second > val) {
            road_map[elem[1]][elem[0]] = val;
        }
    }

    answer = djikstra(1);
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