/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: 서머코딩/윈터코딩(2018)
 * @level: 4
 * @prob_name: 쿠키 구입
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/49995
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isOverRange(int index, int cookie_size) {
    if (index < 0) return false;
    if (index > cookie_size - 1) return false;
    return true;
}

int solution(vector<int> cookie) {
    int answer = 0;
    int cookie_size = cookie.size();

    for (int i = 0; i < cookie_size - 1; i++) {
        int left = cookie[i];
        int left_idx = i;
        int right = cookie[i + 1];
        int right_idx = i + 1;
        while (true) {
            if (left == right) {
                if (left > answer) {
                    answer = left;
                }

                if (isOverRange(left_idx - 1, cookie_size)) {
                    left_idx--;
                    left += cookie[left_idx];
                }
                else {
                    if (isOverRange(right_idx + 1, cookie_size)) {
                        right_idx++;
                        right += cookie[right_idx];
                    }
                    else {
                        break;
                    }
                }
            }
            else {
                if (left > right) {
                    if (isOverRange(right_idx + 1, cookie_size)) {
                        right_idx++;
                        right += cookie[right_idx];
                    }
                    else {
                        break;
                    }
                }
                else {
                    if (isOverRange(left_idx - 1, cookie_size)) {
                        left_idx--;
                        left += cookie[left_idx];
                    }
                    else {
                        break;
                    }
                }
            }
        }
    }
    return answer;
}

int main() {
    vector<int> cookie = {1, 1, 2, 3};
    cout << solution(cookie) << endl;
}