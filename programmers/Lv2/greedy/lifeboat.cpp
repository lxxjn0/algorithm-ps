/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: greedy
 * @level: 2
 * @prob_name: 구명보트
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42885
 */

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int p_back = people.size() - 1;
    int p_front = 0;

    int per1 = 0, per2 = 0;

    sort(people.begin(), people.end());  // 무게 순으로 정렬

    while (p_front <= p_back) {
        if (p_front == p_back) {
            answer++;
            break;  // 모든 사람이 탈출했으므로
        } else {
            per1 = people[p_front];
            per2 = people[p_back];
            if (per1 + per2 <= limit) {
                p_front++;
                p_back--;
                answer++;
            } else if (p_back - p_front == 1) {
                answer += 2;  // 이 두명만 태우면 모두 탈출
                break;
            } else {
                p_back--;
                answer++;
            }
        }
    }

    return answer;
}

int main() {
    vector<int> people = {70, 50, 80, 50};
    int limit = 100;

    cout << solution(people, limit) << endl;
}