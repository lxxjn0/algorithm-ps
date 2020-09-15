/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: binary search
 * @level: 3
 * @prob_name: 입국심사
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/43238
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long max_ = 1000000000000000000;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    long long left = 1;
    long long right = max_;
    long long mid = 0;
    int times_size = times.size();

    long long n_ = n, cal_n = 0;
    while (left < right) {
        mid = (left + right) / 2;
        cal_n = 0;
        for (int i = 0; i < times_size; i++) cal_n += mid / times[i];

        if (n_ <= cal_n) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    answer = right;
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 6;
    vector<int> times = {7, 10};
    cout << solution(n, times) << endl;
}