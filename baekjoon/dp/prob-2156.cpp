/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Dynamic programming
 * @prob_name: 포도주 시식
 * @prob_number: 2156
 * @prob_url: https://www.acmicpc.net/problem/2156
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> wines;
int n = 0;

void makeWines() {
    wines.assign(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> wines[i];
    }
}

int getMaxWineDrink() {
    if (n == 1) {
        return wines[1];
    } else if (n == 2) {
        return wines[1] + wines[2];
    }

    vector<int> dp(n + 1, 0);
    dp[1] = wines[1];
    dp[2] = wines[2] + dp[1];

    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 1], max(dp[i - 3] + wines[i - 1], dp[i - 2]) + wines[i]);
    }
    return dp[n];
}

int main() {
    cin >> n;
    makeWines();

    cout << getMaxWineDrink();
}