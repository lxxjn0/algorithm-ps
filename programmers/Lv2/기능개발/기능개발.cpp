/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: stack/queue
 * @level: 2
 * @prob_name: 기능 개발
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42586
 */

#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

queue<pair<int, int>> q;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int prog_size = progresses.size();
    for (int i = 0; i < prog_size; i++) {
        q.push(make_pair(progresses[i], speeds[i]));
    }

    while (!q.empty()) {
        int cur_prog, speed, q_size;
        q_size = q.size();

        tie(cur_prog, speed) = q.front();
        q.pop();
        if (cur_prog < 100) {
            q.push(make_pair(cur_prog + speed, speed));
            for (int i = 0; i < q_size - 1; i++) {
                tie(cur_prog, speed) = q.front();
                q.pop();
                q.push(make_pair(cur_prog + speed, speed));
            }
        } else {
            int count_prog_num = 1;
            int continue_check = true;
            for (int i = 0; i < q_size - 1; i++) {
                tie(cur_prog, speed) = q.front();
                q.pop();
                if ((cur_prog >= 100) && continue_check) {
                    count_prog_num++;
                } else {
                    continue_check = false;
                    q.push(make_pair(cur_prog + speed, speed));
                }
            }
            answer.push_back(count_prog_num);
        }
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};
    vector<int> answer = solution(progresses, speeds);

    int answer_size = answer.size();
    for (int i = 0; i < answer_size; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}