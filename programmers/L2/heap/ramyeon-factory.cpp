/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: heap
 * @level: 2
 * @prob_name: 라면 공장
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42629
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
priority_queue<int, vector<int>, less<int>> pq;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int v_size = dates.size(), v_idx = 0;

    while (stock < k) {
        int d_tmp = 0, sup_tmp = 0;
        while (v_idx < v_size) {
            d_tmp = dates[v_idx];
            if (d_tmp <= stock) {
                pq.push(supplies[v_idx]);
                v_idx++;
            } else
                break;
        }

        sup_tmp = pq.top();
        pq.pop();
        answer++;
        stock += sup_tmp;
    }

    return answer;
}

int main() {
    int stock = 4;
    vector<int> dates = {4, 10, 15};
    vector<int> supplies = {20, 5, 10};
    int k = 30;

    cout << solution(stock, dates, supplies, k) << endl;
}