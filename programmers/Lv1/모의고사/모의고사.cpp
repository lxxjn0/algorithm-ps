/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: brute_forch
 * @level: 1
 * @prob_name: 모의고사
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42840
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> per1_pattern = {1, 2, 3, 4, 5};
vector<int> per2_pattern = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> per3_pattern = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> max_count = {0, 0, 0};  // per1, per2, per3

    int per1_size = per1_pattern.size();
    int per2_size = per2_pattern.size();
    int per3_size = per3_pattern.size();
    int answ_len = answers.size();

    for (int i = 0; i < answ_len; i++) {
        if (answers[i] == per1_pattern[i % per1_size]) max_count[0]++;
        if (answers[i] == per2_pattern[i % per2_size]) max_count[1]++;
        if (answers[i] == per3_pattern[i % per3_size]) max_count[2]++;
    }

    int max_val = *max_element(max_count.begin(), max_count.end());
    for (int i = 0; i < 3; i++) {
        if (max_val == max_count[i]) answer.push_back(i + 1);
    }

    return answer;
}

int main() {
    vector<int> answers = {1, 3, 2, 4, 2};
    vector<int> answer = solution(answers);

    for (auto elem : answer) {
        cout << elem << " ";
    }
    cout << endl;
}