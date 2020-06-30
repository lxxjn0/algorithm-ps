/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: greedy
 * @level: 3
 * @prob_name: 저울
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42886
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> weight) {
    int answer = 1;
    int weight_size = weight.size();
    sort(weight.begin(), weight.end());
    for(int i = 0; i < weight_size; i++){
        if(answer < weight[i]) {
            break;
        }
        answer += weight[i];
    }

    return answer;
}

int main() {
    vector<int> weight = {3, 1, 6, 2, 7, 30, 1};
    cout << solution(weight) << endl;
}