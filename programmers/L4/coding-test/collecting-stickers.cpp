/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: 서머코딩/윈터코딩(2018)
 * @level: 4
 * @prob_name: 스티커 모으기(2)
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/12971
 */

#include <algorithm>
#include <iostream>
#include <vector>
#define MAX_LEN 100000

using namespace std;

int dp1[MAX_LEN] = {0};
int dp2[MAX_LEN] = {0};
int sticker_size = 0;

void select(vector<int>& sticker) {
    dp1[1] = sticker[1];
    dp1[2] = max(dp1[1], sticker[2]);
    for (int i = 3; i < sticker_size - 2; i++) {
        dp1[i] = max(dp1[i - 2] + sticker[i], dp1[i - 1]);
    }
}

void no_select(vector<int>& sticker) {
    dp2[0] = sticker[0];
    dp2[1] = max(dp2[0], sticker[1]);
    for (int i = 2; i < sticker_size - 1; i++) {
        dp2[i] = max(dp2[i - 2] + sticker[i], dp2[i - 1]);
    }
}

int solution(vector<int> sticker) {
    int answer = 0;
    sticker_size = sticker.size();
    if (sticker_size <= 3) {
        for (auto& elem : sticker) {
            if (elem > answer) answer = elem;
        }
    } else {
        select(sticker);
        no_select(sticker);
        answer = max(dp1[sticker_size - 3] + sticker[sticker_size - 1], dp2[sticker_size - 2]);
    }
    return answer;
}

int main() {
    vector<int> sticker = {2, 1};
    cout << solution(sticker) << endl;
}