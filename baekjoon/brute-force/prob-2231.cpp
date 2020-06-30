/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Brute force
 * @prob_name: 분해합
 * @prob_number: 2231
 * @prob_url: https://www.acmicpc.net/problem/2231
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GetDivideSum(int n) {
    int answer = 0;

    for (int i = 1; i <= n; i++) {
        string num = to_string(i);
        int num_size = num.length();
        int divide_sum = i;

        for (int j = 0; j < num_size; j++) {
            divide_sum += num[j] - '0';
        }

        if (divide_sum == n) {
            answer = i;
            break;
        }
    }
    return answer;
}

int main() {
    int n;
    cin >> n;

    cout << GetDivideSum(n) << endl;
}