/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: hash
 * @level: 2
 * @prob_name: 위장
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42578
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> attributes;

    for (int i = 0; i < clothes.size(); i++) {
        attributes[clothes[i][1]]++;
    }
    for (auto it = attributes.begin(); it != attributes.end(); it++) {
        answer *= (it->second + 1);
    }
    answer--;

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<vector<string>>> clothes = {
        {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}},
        {{"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"}}};

    for (auto elem : clothes) {
        std::cout << solution(elem) << endl;
    }
}