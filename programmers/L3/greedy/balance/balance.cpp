/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: greedy
 * @level: 3
 * @prob_name: 저울
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42886
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> pair_;
vector<pair_> weightVec;

// 가능하면 true 리턴
bool DFS(int target, int pos) {
    if (target == 0) return true;
    if (target < 0) return false;

    for (int i = pos; i >= 0; i--) {
        if (weightVec[i].second > 0) {
            weightVec[i].second--;
            if (DFS(target - weightVec[i].first, i)) {
                weightVec[i].second++;
                return true;
            } else {
                weightVec[i].second++;
            }
        }
    }

    return false;
}

int solution(vector<int> weight) {
    int answer = 1;
    map<int, int> weightCount;

    if (*min_element(weight.begin(), weight.end()) != 1) return 1;
    if (*max_element(weight.begin(), weight.end()) == 1) return weight.size() + 1;

    for (auto elem : weight) {
        weightCount[elem]++;
        answer += elem;
    }

    for (auto elem : weightCount) weightVec.push_back(make_pair(elem.first, elem.second));
    int weightVec_size = weightVec.size();

    int min_num = 1;
    while (min_num < answer) {
        bool check = false;
        int i;
        for (i = 0; i < weightVec_size; i++) {
            if (weightVec[i].first == min_num) {
                min_num++;
                check = true;
                break;
            } else if (weightVec[i].first > min_num) {
                break;
            }
        }

        if (!check) {
            if (DFS(min_num, i - 1)) {
                min_num++;
            } else {
                return min_num;
            }
        }
    }
    return answer;
}

int main() {
    vector<int> weight = {3, 1, 6, 2, 7, 30, 1};
    cout << solution(weight) << endl;
}