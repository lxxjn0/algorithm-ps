/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: greedy
 * @level: 1
 * @prob_name: 체육복
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42862
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lost_size, reserve_size, class_num;
bool reserved[31] = {false};

void reserve_class(vector<int>& lost, vector<int>& reserve) {
    for (int i = 0; i < reserve_size; i++) {
        if (reserve[i] == -1) {
            class_num++;
            continue;
        }

        for (int j = 0; j < lost_size; j++) {
            if (!reserved[lost[j]] && (lost[j] == reserve[i] - 1)) {
                reserved[lost[j]] = true;
                class_num++;
                break;
            } else if (!reserved[lost[j]] && (lost[j] == reserve[i] + 1)) {
                reserved[lost[j]] = true;
                class_num++;
                break;
            }
        }
    }
}

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    lost_size = lost.size();
    reserve_size = reserve.size();
    class_num = n - lost_size;

    for (int i = 0; i < reserve_size; i++) {
        for (int j = 0; j < lost_size; j++) {
            if (reserve[i] == lost[j]) {
                reserved[reserve[i]] = true;
                reserve[i] = -1;
                break;
            }
        }
    }

    reserve_class(lost, reserve);
    answer = class_num;

    return answer;
}

int main() {
    int n = 5;
    vector<int> lost = {2, 4};
    vector<int> reserve = {3};
    cout << solution(n, lost, reserve) << endl;
}