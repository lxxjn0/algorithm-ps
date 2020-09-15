/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: dynamic programming
 * @level: 3
 * @prob_name: 정수 삼각형
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/43105
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int d[500][500];

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    int max_height = triangle.size();  // 최대 높이 == 마지막 밑변 넓이
    for (int i = 0; i < max_height; i++) {
        d[max_height - 1][i] = triangle[max_height - 1][i];
    }

    for (int i = max_height - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            d[i][j] = triangle[i][j];
            d[i][j] += max(d[i + 1][j], d[i + 1][j + 1]);
        }
    }
    answer = d[0][0];
    return answer;
}

int main() {
    vector<vector<int>> triangle = {
        {7},
        {3, 8},
        {8, 1, 0},
        {2, 7, 4, 4},
        {4, 5, 2, 6, 5}};
    cout << solution(triangle) << endl;
}