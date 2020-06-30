/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: stack/queue
 * @level: 2
 * @prob_name: 쇠막대기
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42585
 */

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef pair<char, int> bracket;
typedef pair<int, int> stick;

int solution(string arrangement) {
    int answer = 0;
    stack<bracket> s;      // 괄호의 인덱스를 순서대로 저장
    vector<int> laser;     // 레이저일 경우 괄호의 앞 인덱스를 저장할 vector
    vector<stick> sticks;  // 막대기들의 시작 인덱스와 끝 인덱스를 tuple로 저장

    int top_idx = 0;
    bracket cur_bracket;  // stack의 top을 가져와서 저장할 변수
    int arrangement_size = arrangement.size();
    for (int i = 0; i < arrangement_size; ++i) {
        if (arrangement[i] == '(')
            s.push(make_pair('(', i));
        else {
            cur_bracket = s.top();
            s.pop();
            // 현재 인덱스와 '(' 브라켓의 인덱스 차이가 1이면 레이저이고, 1보다 크면 막대기
            if (i - cur_bracket.second == 1)
                laser.push_back(cur_bracket.second);
            else
                sticks.push_back(make_pair(cur_bracket.second, i));
        }
    }
    int laser_cnt = 0, cur_laser = 0;
    int sticks_size = sticks.size();
    int laser_size = laser.size();
    stick cur_stick;  // vector에 저장된 막대기를 가져와서 저장할 변수
    for (int i = 0; i < sticks_size; ++i) {
        laser_cnt = 0;
        cur_stick = sticks[i];
        for (int j = 0; j < laser_size; ++j) {
            cur_laser = laser[j];
            if (cur_laser > cur_stick.first && cur_laser < cur_stick.second) laser_cnt++;
        }
        answer += laser_cnt + 1;
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string arrangement = "()(((()())(())()))(())";
    cout << solution(arrangement) << endl;
}