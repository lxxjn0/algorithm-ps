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
    int ans = 0;

    while (true) {
        if (n == 1) {
            ans++;
            break;
        }

        if (n % 2 == 0) {
            n /= 2;
        } else {
            n--;
            ans++;
        }
    }

    return ans;
}

int main() {
    int n = 6;
    cout << solution(n) << endl;
}