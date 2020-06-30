/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: greedy
 * @level: 2
 * @prob_name: 조이스틱
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42860
 */

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#define MAX_NUM 100000000
#define MIN_NUM -100000000

using namespace std;

//bool visited[20] = { false };

int solution(string name) {
    int answer = 0;
    vector<int> visited;

    int name_size = name.size();
    string tmp = name;
    sort(tmp.begin(), tmp.end());

    char ch = 'A';
    int tmp_idx = 0, ch_idx = 0;
    while (tmp_idx < name_size) {
        if (tmp[tmp_idx] == ch + ch_idx) {                        // 'A' + ch_idx와 같은 알파벳일 경우
            if (name[tmp_idx] != ch) visited.push_back(tmp_idx);  // A가 아닌 경우 visitied에 true
            tmp_idx++;                                            // 다음 문자로 이동
            if (ch_idx <= 26 - ch_idx)
                answer += ch_idx;  // 위로 이동
            else
                answer += (26 - ch_idx);  // 아래로 이동
        } else
            ch_idx++;
    }

    // 첫번째 문자부터 시작하는데 만약 첫번째 문자가 A가 아니여서 vector에 저장되어 있다면 삭제
    if (visited[0] == 0) visited.erase(visited.begin() + 0);
    int vis_size = visited.size();
    int min_dis = MAX_NUM;
    int min_tmp = min(name_size - visited[0], visited[vis_size - 1]);
    if (min_dis > min_tmp) min_dis = min_tmp;
    for (int i = 0; i < vis_size - 1; i++) {
        int r_gap = visited[i];
        int l_gap = name_size - visited[i + 1];
        min_tmp = min(r_gap * 2 + l_gap, r_gap + l_gap * 2);
        if (min_dis > min_tmp) min_dis = min_tmp;
    }

    answer += min_dis;
    return answer;
}

int main() {
    string name = "CANAAAAANAN";
    cout << solution(name) << endl;
}