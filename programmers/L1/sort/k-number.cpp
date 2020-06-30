/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: sort
 * @level: 1
 * @prob_name: K번째수
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42748
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    vector<int> tmp;

    for (int i = 0; i < commands.size(); i++) {
        tmp = array;
        sort(tmp.begin() + commands[i][0] - 1, tmp.begin() + commands[i][1]);
        answer.push_back(tmp[commands[i][0] + commands[i][2] - 2]);
    }

    return answer;
}

int main() {
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {
        {2, 5, 3},
        {4, 4, 1},
        {1, 7, 3}};

    vector<int> answer = solution(array, commands);
    int answer_size = answer.size();
    for (int i = 0; i < answer_size; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
}