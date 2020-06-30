/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Dynamic programming
 * @prob_name: 연속합
 * @prob_number: 1912
 * @prob_url: https://www.acmicpc.net/problem/1912
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> sequence;
int n = 0;

void makeSequence() {
    sequence.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
}

int getMaxSequence() {
    vector<int> dp(n, 0);
    dp[0] = sequence[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(sequence[i], dp[i - 1] + sequence[i]);
    }
    return *max_element(dp.begin(), dp.end());
}

int main() {
    cin >> n;
    makeSequence();

    cout << getMaxSequence();
}