/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: dynamic programming
 * @level: 3
 * @prob_name: 등굣길
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42898
 */

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define DIV 1000000007

using namespace std;

int d[101][101] = {0};

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    d[0][1] = 1;

    int new_m = m, new_n = n;
    int pud_size = puddles.size();
    sort(puddles.begin(), puddles.end());
    for (int i = pud_size - 1; i >= 0; i--) {
        d[puddles[i][0]][puddles[i][1]] = -1;
        if ((puddles[i][0] == new_m) && (puddles[i][1] == new_n)) {
            answer = 0;
            return 0;
        }
        if ((puddles[i][0] == new_m) && (puddles[i][1] == (new_n - 1)))
            new_m -= 1;
        else if ((puddles[i][0] == (new_m - 1)) && (puddles[i][1] == new_n))
            new_n -= 1;
    }

    for (int i = 1; i <= new_m; i++) {
        for (int j = 1; j <= new_n; j++) {
            int cur = d[i][j], up = d[i - 1][j], left = d[i][j - 1];
            if (cur == -1) continue;
            if ((up == -1) && (left == -1))
                d[i][j] = 0;
            else if (up == -1)
                d[i][j] = left;
            else if (left == -1)
                d[i][j] = up;
            else
                d[i][j] = (up + left) % DIV;
        }
    }

    answer = d[new_m][new_n];

    return answer;
}

int main() {
    int m = 4;
    int n = 3;
    vector<vector<int>> puddles = {{2, 2}};
    cout << solution(m, n, puddles) << endl;
}