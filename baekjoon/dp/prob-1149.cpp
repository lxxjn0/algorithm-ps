/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Dynamic Programming
 * @prob_name: RGB거리
 * @prob_number: 1149
 * @prob_url: https://www.acmicpc.net/problem/1149
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define RED 0
#define GREEN 1
#define BLUE 2
#define COLOR_NUM 3

using namespace std;

vector<vector<int>> paint_price;
int n = 0;

void InputPaintPrice() {
    paint_price.assign(n + 1, vector<int>(COLOR_NUM, 0));
    for (int i = 1; i <= n; i++) {
        cin >> paint_price[i][RED] >> paint_price[i][GREEN] >> paint_price[i][BLUE];
    }
}

int GetMinPaintPrice() {
    if (n == 1) {
        return *min_element(paint_price[1].begin(), paint_price[1].end());
    }

    vector<vector<int>> dp(n + 1, vector<int>(COLOR_NUM, 0));
    dp[1][RED] = paint_price[1][RED];
    dp[1][GREEN] = paint_price[1][GREEN];
    dp[1][BLUE] = paint_price[1][BLUE];

    for (int i = 2; i <= n; i++) {
        dp[i][RED] = min(dp[i - 1][GREEN], dp[i - 1][BLUE]) + paint_price[i][RED];
        dp[i][GREEN] = min(dp[i - 1][RED], dp[i - 1][BLUE]) + paint_price[i][GREEN];
        dp[i][BLUE] = min(dp[i - 1][RED], dp[i - 1][GREEN]) + paint_price[i][BLUE];
    }
    return *min_element(dp[n].begin(), dp[n].end());
}

int main() {
    cin >> n;

    InputPaintPrice();
    cout << GetMinPaintPrice();
}