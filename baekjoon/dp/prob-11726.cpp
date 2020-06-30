/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Dynamic programming
 * @prob_name: 2xn 타일링
 * @prob_number: 11726
 * @prob_url: https://www.acmicpc.net/problem/11726
 */

#include <iostream>
#include <string>
#include <vector>

#define DIV_NUM 10007

using namespace std;

int GetTilefilling(int n) {
    if (n == 1) {
        return 1;
    }

    vector<int> dp(n + 1, 0);

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % DIV_NUM;
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;

    cout << GetTilefilling(n);
}