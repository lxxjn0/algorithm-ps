/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: sort
 * @level: 2
 * @prob_name: H-index
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42747
 */

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int ci_size = citations.size();
    sort(citations.begin(), citations.end());

    for (int i = 0; i < ci_size; i++) {
        if (citations[i] >= ci_size - i) {
            answer = ci_size - i;
            return answer;
        }
    }

    return answer;
}

int main() {
    vector<int> citations = {3, 0, 6, 1, 5};
    cout << solution(citations) << endl;
}