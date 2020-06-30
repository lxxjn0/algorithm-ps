/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: stack/queue
 * @level: 2
 * @prob_name: 주식가격
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42584
 */

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef pair<int, int> pair_;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    stack<pair_> s;
    int prices_size = prices.size();

    pair_ tmp_pair = make_pair(prices[0], 0);
    s.push(tmp_pair);
    answer.push_back(0);
    for (int i = 1; i < prices_size; i++) {
        answer.push_back(0);
        while (tmp_pair.first > prices[i]) {
            answer[tmp_pair.second] = i - tmp_pair.second;
            s.pop();
            if (s.empty()) break;
            tmp_pair = s.top();
        }
        s.push(make_pair(prices[i], i));
        tmp_pair = s.top();
    }

    while (!s.empty()) {
        tmp_pair = s.top();
        s.pop();
        answer[tmp_pair.second] = prices_size - 1 - tmp_pair.second;
    }

    return answer;
}

int main() {
    vector<int> prices = {1, 2, 3, 2, 3};
    vector<int> answer = solution(prices);
    for (auto elem : answer) {
        cout << elem << " ";
    }
    cout << endl;
}