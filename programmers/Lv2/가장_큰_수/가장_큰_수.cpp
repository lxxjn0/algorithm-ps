/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: sort
 * @level: 2
 * @prob_name: 가장 큰 수
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42746
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(string a, string b) {
    if (a + b > b + a) return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> num_str;

    for (auto num : numbers) {
        num_str.push_back(to_string(num));
    }

    sort(num_str.begin(), num_str.end(), compare);

    for (auto num : num_str) {
        answer += num;
    }

    if (answer[0] == '0') answer = "0";

    return answer;
}

int main() {
    vector<int> numbers = {6, 10, 2};
    cout << solution(numbers) << endl;
}