/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: 서머코딩/윈터코딩(2019)
 * @level: 3
 * @prob_name: 종이접기
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/62049
 */

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    int answer_size = pow(2, n) - 1;
    answer.assign(answer_size, 0);

    for (int i = 2; i <= n; i++) {
        int tmp_pow = pow(2, i);
        for (int j = tmp_pow - 1; j > pow(2, i - 1); j--) {
            answer[j - 1] = !answer[(tmp_pow - j) - 1];
        }
    }
    return answer;
}

int main() {
    int n = 5;
    vector<int> answer = solution(n);
    for (auto elem : answer) {
        cout << elem << " ";
    }
    cout << endl;
}