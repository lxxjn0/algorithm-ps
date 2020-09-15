/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: 서머코딩/윈터코딩(2018)
 * @level: 2
 * @prob_name: 점프와 순간 이동
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/12980
 */

#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> d(n + 1, 0);

    d[0] = 0;
    d[1] = 1;

    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            d[i] = d[i / 2];
        } else {
            d[i] = d[i - 1] + 1;
        }
    }

    return d[n];
}

int main() {
    int n = 6;
    cout << solution(n) << endl;
}