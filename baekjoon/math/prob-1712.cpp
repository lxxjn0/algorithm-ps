/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Math
 * @prob_name: 손익분기점
 * @prob_number: 1712
 * @prob_url: https://www.acmicpc.net/problem/1712
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getBreakEvenPoint(int a, int b, int c) {
    if (b >= c) {
        return -1;
    }

    int profit = c - b;

    return a / profit + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a;
    int b;
    int c;
    cin >> a >> b >> c;

    cout << getBreakEvenPoint(a, b, c);
}