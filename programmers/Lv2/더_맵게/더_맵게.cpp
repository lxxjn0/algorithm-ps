/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: heap
 * @level: 2
 * @prob_name: 더 맵게
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42626
 */

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int cnt = 0;
    int sco_size = scoville.size();
    int min_1 = 0, min_2 = 0, pq_size = 0;
    long long sum = 0;

    for (int i = 0; i < sco_size; i++) pq.push(scoville[i]);

    while (1) {
        pq_size = pq.size();
        if (pq_size < 2) {
            if (pq.top() >= K)
                return cnt;
            else
                return -1;
        } else {
            min_1 = pq.top();
            pq.pop();
            min_2 = pq.top();
            pq.pop();
            cnt++;
            sum = min_1 + (min_2 * 2);
            pq.push(sum);
            if (K <= pq.top()) return cnt;
        }
    }
}

int main() {
    vector<int> scoville = {1, 2, 3, 9, 10, 12};
    int K = 7;

    cout << solution(scoville, K) << endl;
}