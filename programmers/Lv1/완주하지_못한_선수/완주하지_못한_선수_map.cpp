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
    unordered_map<string, int> hash_map;

    for (auto name : completion) {
        hash_map[name]++;
    }

    for (auto name : participant) {
        if (hash_map.end() == hash_map.find(name)) {
            return name;
        } else {
            hash_map[name]--;

            if (hash_map[name] < 0) {
                return name;
            }
        }
    }
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