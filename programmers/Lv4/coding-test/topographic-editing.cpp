/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: 서머코딩/윈터코딩(2018) - parametric search
 * @level: 4
 * @prob_name: 지형 편집
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/12984
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

long long p;
long long q;

long long getCost(vector<vector<int>>& land, int height) {
    long long height_cost = 0;
    long long op = 0;
    int land_size = land.size();
    for (int i = 0; i < land_size; i++) {
        for (int j = 0; j < land_size; j++) {
            height_cost += (long long)(land[i][j] - height) * (land[i][j] > height ? q : -p);
        }
    }
    return height_cost;
}

long long solution(vector<vector<int>> land, int P, int Q) {
    long long answer = -1;
    p = P;
    q = Q;

    int mid_height = 0;
    int left_height = 0;
    int right_height = 1e9;

    long long mid_cost = 0;
    long long mid_prev_cost = 0;

    while (left_height < right_height - 1) {
        mid_height = (left_height + right_height) / 2;
        mid_cost = getCost(land, mid_height);
        mid_prev_cost = getCost(land, mid_height - 1);
        if (mid_cost > mid_prev_cost) {
            right_height = mid_height;
        } else {
            left_height = mid_height;
        }
    }
    return min(getCost(land, left_height), getCost(land, right_height));
}

int main() {
    vector<vector<int>> land = {
        {4, 4, 3},
        {3, 2, 2},
        {2, 1, 0}};
    int P = 5;
    int Q = 3;
    cout << solution(land, P, Q) << endl;
}