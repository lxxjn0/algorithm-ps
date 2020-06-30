/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: hash
 * @level: 1
 * @prob_name: 완주하지 못한 선수
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42576
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    int completion_size = completion.size();
    for (int i = 0; i < completion_size; i++) {
        if (participant[i] != completion[i]) {
            answer = participant[i];
            return answer;
        }
    }

    answer = participant[participant.size() - 1];
    return answer;
}

int main() {
    vector<vector<string>> participant = {
        {"leo", "kiki", "eden"},
        {"marina", "josipa", "nikola", "vinko", "filipa"},
        {"mislav", "stanko", "mislav", "ana"}};

    vector<vector<string>> completion = {
        {"eden", "kiki"},
        {"josipa", "filipa", "marina", "nikola"},
        {"stanko", "ana", "mislav"}};

    for (int i = 0; i < 3; i++) {
        cout << solution(participant[i], completion[i]) << endl;
    }
}