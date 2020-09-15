/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: binary search
 * @level: 3
 * @prob_name: 예산
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/43237
 */

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> budgets, int M) {
    int answer = 0;
    int bud_size = budgets.size(), i = 0;  // budgets size

    sort(budgets.begin(), budgets.end());  // 오름차순으로 정렬

    // 예산의 총합이 총 예산보다 작을 경우
    long long total_bud = 0;  // 예산의 총합

    for (i = 0; i < bud_size; i++) total_bud += budgets[i];
    if (total_bud <= M) return budgets.back();
    ;

    // 아닐 경우
    int cur_idx = 0, cur_sum = 0, cur_bud = 0;
    int avg = M / bud_size;

    while (cur_bud < avg) {
        for (i = cur_idx; i < bud_size; ++i) {
            cur_bud = budgets[i];
            if (cur_bud >= avg) {
                cur_idx = i;
                break;
            }
            M -= cur_bud;
        }
        avg = M / (bud_size - cur_idx);
    }
    return avg;
}

int main() {
    vector<int> budgets = {170, 150, 108, 127, 110, 162, 140, 131, 138};
    int M = 1193;
    cout << solution(budgets, M) << endl;
}