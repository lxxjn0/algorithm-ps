/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: greedy
 * @level: 3
 * @prob_name: 섬 연결하기
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42861
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

list<int> adjust[100];  // 인접 리스트
int u_root[100] = {0};  // root를 저장할 배열
int u_rank[100] = {0};  // 높이를 저장할 배열

void make_set(int size) {  // Union root 배열과 rank 배열 초기화
    int i = 0;
    for (i = 0; i < size; i++) {
        u_root[i] = i;
        u_rank[i] = 0;
    }
}

int find_rt(int x) {  // root를 찾는 함수
    if (u_root[x] == x)
        return x;
    else
        return u_root[x] = find_rt(u_root[x]);  // root를 찾아서 최종루트로 초기화 후 return
}

bool union_set(int x, int y) {
    x = find_rt(x);
    y = find_rt(y);

    if (x == y)
        return true;  // root가 같으면 이미 사이클 생성
    else {
        if (u_rank[x] < u_rank[y])
            u_root[x] = y;
        else if (u_rank[x] > u_rank[y])
            u_root[y] = x;
        else {
            u_root[y] = x;
            u_rank[x]++;  // 높이가 같다면 높이가 1 증가하므로 x에 높이 증가
        }
        return false;
    }
}

bool compare(vector<int> a, vector<int> b) {
    return a[2] < b[2];
}

int kruskal(vector<vector<int>>& costs) {
    int total_cost = 0;
    int costs_size = costs.size();
    sort(costs.begin(), costs.end(), compare);

    for (int i = 0; i < costs_size; i++) {
        if (!union_set(costs[i][0], costs[i][1])) {
            total_cost += costs[i][2];
        }
    }
    return total_cost;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    for (auto elem : costs) {
        adjust[elem[0]].push_back(elem[1]);
    }
    make_set(n);

    answer = kruskal(costs);
    return answer;
}

int main() {
    int n = 4;
    vector<vector<int>> costs = {
        {0, 1, 1},
        {0, 2, 2},
        {1, 2, 5},
        {1, 3, 1},
        {2, 3, 8}};
    cout << solution(n, costs) << endl;
}