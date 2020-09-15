/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: dynamic programming
 * @level: 3
 * @prob_name: N으로 표현
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42895
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

#define PLUS 0
#define MINUS 1
#define MULTI 2
#define DIV 3
#define CST_OV 9

using namespace std;

unordered_set<int> costs[9];

int cal(int oper, int first, int second) {
    int tmp, result = 0;
    if (oper == PLUS) result = first + second;
    if (oper == MINUS) result = first - second;
    if (oper == MULTI) result = first * second;
    if (oper == DIV) result = first / second;
    return result;
}

void search_cost(int N, int cost) {
    int seq_N = 0;

    for (int i = 0; i < cost; i++) {
        seq_N = seq_N * 10 + N;
    }

    costs[cost].insert(seq_N);

    int cal_val;
    for (int i = 1; i < cost; i++) {
        for (auto c_front : costs[i]) {
            for (auto c_back : costs[cost - i]) {
                for (int j = 0; j < 4; j++) {
                    cal_val = cal(j, c_front, c_back);
                    if (cal_val < 1 || cal_val > 32000) continue;
                    costs[cost].insert(cal_val);
                }
            }
        }
    }
}

int solution(int N, int number) {
    int answer = -1;

    for (int i = 1; i <= 8; i++) {
        search_cost(N, i);
        if (costs[i].end() != costs[i].find(number)) {
            answer = i;
            return answer;
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //cout << solution(5, 12) << '\n';
    cout << solution(5, 12) << '\n';
}