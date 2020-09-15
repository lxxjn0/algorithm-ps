/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: dynamic programming
 * @level: 4
 * @prob_name: 서울에서 경산까지
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42899
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

#define MAX_T 101         // travel 배열의 index를 1부터 받기위해
#define MAX_K 100001      // 0 <= K <= 1000000
#define MIN_M -100000000  // K가 음수값을 가질 경우 할ptr : 채우고자 하는 메모리의 시작 포인터 (시작 주소)당하기 위한 음수 값

using namespace std;

/* dp배열, d[K][n] k시간내에 n지역에 도착하여 얻을 수 있는 최대 금액
n이 travel.size()와 같을 때가 우리가 원하는 값 */
int d[MAX_K][MAX_T] = {0};

int td_travel(int K, int T, vector<vector<int>>& travel) {
    if (T == 0)  // K가 음수이면 시간을 초과하는 케이스이므로
        return 0;
    else if (d[K][T] != -1) {
        return d[K][T];
    } else {
        int walk = 0, bike = 0;
        int walk_k = K - travel[T - 1][0];  // walk 선택으로 들어갈 값
        int bike_k = K - travel[T - 1][2];  // bike 선택으로 들어갈 값
        if (walk_k >= 0)
            walk = td_travel(walk_k, T - 1, travel) + travel[T - 1][1];
        else
            walk = MIN_M;
        if (bike_k >= 0)
            bike = td_travel(bike_k, T - 1, travel) + travel[T - 1][3];
        else
            bike = MIN_M;

        d[K][T] = max(walk, bike);
        return max(walk, bike);
    }
}

int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    int travel_size = travel.size();

    if (K == 0) return 0;

    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= travel_size; j++) {
            d[i][j] = -1;
        }
    }

    answer = td_travel(K, travel_size, travel);

    if (answer < 0) answer = 0;
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* int K = 1650;
    vector<vector<int>> travel = {
        {500, 200, 200, 100},
        {800, 370, 300, 120},
        {700, 250, 300, 90}};  // answer = 660 */
    int K = 3000;
    vector<vector<int>> travel = {
        {1000, 2000, 300, 700},
        {1100, 1900, 400, 900},
        {900, 1800, 400, 700},
        {1200, 2300, 500, 1200}};  // answer = 5900
    cout << solution(K, travel) << endl;
}