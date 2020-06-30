/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: 서머코딩/윈터코딩(2018)
 * @level: 3
 * @prob_name: 기지국 설치
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/12979
 */

#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    int pos = 1;
    vector<int> ranges;

    for (auto& station : stations) {
        ranges.push_back(station - w - pos);
        pos = station + w + 1;
    }
    ranges.push_back(n - pos + 1);

    for (auto& range : ranges) {
        if (range <= 0) {
            continue;
        } else if ((range % (2 * w + 1)) == 0) {
            answer += range / (2 * w + 1);
        } else {
            answer += (range / (2 * w + 1) + 1);
        }
    }
    return answer;
}

int main() {
    int n = 16;
    vector<int> stations = {1};
    int w = 7;
    cout << solution(n, stations, w) << endl;
}