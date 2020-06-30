/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Dynamic programming
 * @prob_name: 이친수
 * @prob_number: 2193
 * @prob_url: https://www.acmicpc.net/problem/2193
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef pair<long long, long long> longLongPair;
int n = 0;

long long getPinaryNumber() {
    if (n == 1) {
        return 1;
    }
    vector<longLongPair> dp(n + 1, make_pair(0, 0));
    dp[1] = make_pair(0, 1);

    for (int i = 2; i <= n; i++) {
        dp[i] = make_pair(dp[i - 1].first + dp[i - 1].second, dp[i - 1].first);
    }
    return dp[n].first + dp[n].second;
}

int main() {
    cin >> n;
    
    cout << getPinaryNumber();
}