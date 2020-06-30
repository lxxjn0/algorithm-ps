/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Dynamic programming
 * @prob_name: 정수 삼각형
 * @prob_number: 1932
 * @prob_url: https://www.acmicpc.net/problem/1932
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> triMap;
int n = 0;

void makeTriMap() {
    triMap.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> triMap[i][j];
        }
    }
}

int getMaxTriSum() {
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            triMap[i][j] = triMap[i][j] + max(triMap[i + 1][j], triMap[i + 1][j + 1]);
        }
    }
    return triMap[0][0];
}

int main() {
    cin >> n;

    makeTriMap();
    cout << getMaxTriSum() << endl;
}