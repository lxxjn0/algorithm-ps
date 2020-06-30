/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: 서머코딩/윈터코딩(2018)
 * @level: 2
 * @prob_name: 스킬트리
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/49993
 */

#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int skillSize = skill.size();

    string makePattern = "[^" + skill + "]";
    regex pattern(makePattern);

    for (auto elem : skill_trees) {
        string result = regex_replace(elem, pattern, "");
        int result_size = result.size();
        if (skill.substr(0, result_size) == result) answer++;
    }
    
    return answer;
}

int main() {
    string skill = "CBD";
    vector<string> skill_tree = {"BACDE", "CBADF", "AECB", "BDA"};
    cout << solution(skill, skill_tree);
}