/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: stack/queue
 * @level: 2
 * @prob_name: 탑
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42588
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<pair<int, int>> fir_s;
    stack<pair<int, int>> sec_s;
    int h_size = heights.size();

    for (int i = 0; i < h_size - 1; i++) {
        fir_s.push(make_pair(i + 1, heights[i]));
        answer.push_back(0);
    }
    sec_s.push(make_pair(h_size, heights[h_size - 1]));
    answer.push_back(0);

    int idx = 0, cur_h = 0;
    int tmp_idx = 0, tmp_h = 0;
    while (!fir_s.empty()) {
        tie(idx, cur_h) = fir_s.top();
        fir_s.pop();
        while (!sec_s.empty()) {
            tie(tmp_idx, tmp_h) = sec_s.top();
            sec_s.pop();
            if (cur_h > tmp_h)
                answer[tmp_idx - 1] = idx;
            else {
                sec_s.push(make_pair(tmp_idx, tmp_h));
                break;
            }
        }
        sec_s.push(make_pair(idx, cur_h));
    }

    return answer;
}

int main() {
    vector<int> heights = {6, 9, 5, 7, 4};
    vector<int> answer = solution(heights);

    for (auto elem : answer) {
        cout << elem << " ";
    }
    cout << endl;
}