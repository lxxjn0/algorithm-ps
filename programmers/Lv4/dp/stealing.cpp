/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: dynamic programming
 * @level: 4
 * @prob_name: 도둑질
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42897
 */

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define HOME_NUM 1000000  // 집의 개수

using namespace std;
// d[n][0]는 n을 뽑을 때 최댓값, d[n][1]은 n을 뽑지 않을 때 최댓값
int d1[HOME_NUM][2] = {0};  // n 선택 O
int d2[HOME_NUM][2] = {0};  // n 선택 X

int dp1_with_n(vector<int>& money, int m_size) {
    int i = 0, w_n = 0, wo_n = 0;
    d1[1][0] = money[1];
    for (i = 2; i < m_size - 2; i++) {
        w_n = d1[i - 1][0], wo_n = d1[i - 1][1];
        d1[i][0] = wo_n + money[i];
        d1[i][1] = max(w_n, wo_n);
    }
    return max(d1[m_size - 3][0], d1[m_size - 3][1]);
}

int dp2_without_n(vector<int>& money, int m_size) {
    int i = 0, w_n = 0, wo_n = 0;
    d2[0][0] = money[0];
    for (i = 1; i < m_size - 1; i++) {
        w_n = d2[i - 1][0], wo_n = d2[i - 1][1];
        d2[i][0] = wo_n + money[i];
        d2[i][1] = max(w_n, wo_n);
    }
    return max(d2[m_size - 2][0], d2[m_size - 2][1]);
}

int solution(vector<int> money) {
    int answer = 0;
    int m_size = money.size();
    int dp1_w_n = 0, dp2_wo_n = 0;
    dp1_w_n = dp1_with_n(money, m_size);
    dp2_wo_n = dp2_without_n(money, m_size);

    answer = max(dp1_w_n + money[m_size - 1], dp2_wo_n);

    return answer;
}

int main() {
    vector<int> money = {1, 2, 3, 1};
    cout << solution(money) << endl;
}