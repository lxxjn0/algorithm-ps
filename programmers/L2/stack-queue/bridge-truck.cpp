/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: stack/queue
 * @level: 2
 * @prob_name: 다리를 지나는 트럭
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42583
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

queue<pair<int, int>> q;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int truck_size = truck_weights.size();

    // 다리 길이가 1일 경우
    if (bridge_length == 1) return truck_size + 1;

    // 다리 길이가 1보다 클 경우
    int front_w = 0, front_t = 0, cur_t = 1, cur_w = 0;
    int next_w = 0, w_idx = 1;
    cur_w = truck_weights[0];
    q.push(make_pair(cur_w, cur_t + bridge_length - 1));
    cur_t++;
    while (w_idx < truck_size) {
        next_w = truck_weights[w_idx];
        if (!q.empty()) tie(front_w, front_t) = q.front();

        if (cur_w + next_w <= weight) {
            q.push(make_pair(next_w, cur_t + bridge_length - 1));
            cur_w += next_w;
            w_idx++;
        } else
            cur_t = front_t;

        if (front_t == cur_t) {
            q.pop();           // 가장 앞의 트럭을 끝까지 보냄
            cur_w -= front_w;  // 앞 트럭 무게 감소
        }
        cur_t++;
    }

    while (!q.empty()) {
        tie(front_w, front_t) = q.front();
        q.pop();
    }
    answer = front_t + 1;
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int bridge_length = 2;
    int weight = 10;
    vector<int> truck_weights = {7, 4, 5, 6};

    cout << solution(bridge_length, weight, truck_weights) << endl;
}