/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: 서머코딩/윈터코딩(2018)
 * @level: 1
 * @prob_name: 예산
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/12982
 */

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int d_size = d.size();
    sort(d.begin(), d.end());

    while (budget >= 0 && d_size > answer) {
        budget -= d[answer++];
    }
    if (budget < 0) answer--;

    return answer;
}

int main() {
    vector<int> d = {1, 3, 2, 5, 4};
    int budget = 9;
    cout << solution(d, budget) << endl;
}