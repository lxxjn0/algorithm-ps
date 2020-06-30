/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: stack/queue
 * @level: 2
 * @prob_name: 프린터
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42587
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
queue<pair<int, bool>> q;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    int size_job = priorities.size();
    for (int i = 0; i < size_job; i++) {
        if (i == location)
            q.push(make_pair(priorities[i], true));
        else
            q.push(make_pair(priorities[i], false));
    }

    int pri = 0, q_size = 0;
    bool selected = false, check = false;
    int print_count = 0;
    while (!q.empty()) {
        tie(pri, selected) = q.front();
        q.pop();

        q_size = q.size();
        int tmp_pri = 0;
        bool tmp_selected = false;

        for (int i = 0; i < q_size; i++) {
            tie(tmp_pri, tmp_selected) = q.front();
            q.pop();
            if (tmp_pri > pri) check = true;
            q.push(make_pair(tmp_pri, tmp_selected));
        }

        if (!check) {
            print_count++;
            if (selected) break;
        } else {
            check = false;
            q.push(make_pair(pri, selected));
        }
    }

    answer = print_count;
    return answer;
}

int main() {
    vector<int> priorities = {1, 1, 9, 1, 1, 1};
    int location = 0;

    cout << solution(priorities, location) << endl;
}