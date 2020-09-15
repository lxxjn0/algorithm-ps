/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: dynamic programming
 * @level: 3
 * @prob_name: 타일 장식물
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/43104
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long d[2] = {0};

long long round_rec(int N) {
    long long cur_sq = 1, next_sq = 1;
    d[1] = 4;
    int cache_switch = 1;

    for (int i = 2; i <= N; i++) {
        cur_sq = next_sq;
        d[!cache_switch] = d[cache_switch] + cur_sq * 2;
        next_sq = d[cache_switch] / 2;
        cache_switch = !cache_switch;
    }

    return d[cache_switch];
}

long long solution(int N) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long answer = 0;
    answer = round_rec(N);

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << solution(5) << '\n';
}