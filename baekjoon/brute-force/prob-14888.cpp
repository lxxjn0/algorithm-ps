/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Brute force
 * @prob_name: 연산자 끼워넣기
 * @prob_number: 14888
 * @prob_url: https://www.acmicpc.net/problem/14888
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define OPERATORS 4
#define PLUS 0
#define MINUS 1
#define MUL 2
#define DIV 3

using namespace std;

vector<int> operVec;
vector<int> nums;
int n = 0;

void makeVec() {
    nums.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < OPERATORS; i++) {
        int curOperCount;
        cin >> curOperCount;

        for (int j = 0; j < curOperCount; j++) {
            operVec.push_back(i);
        }
    }
}

int calcByOper(int num1, int num2, int op) {
    if (op == PLUS) {
        return num1 + num2;
    }
    if (op == MINUS) {
        return num1 - num2;
    }
    if (op == MUL) {
        return num1 * num2;
    }
    return num1 / num2;
}

vector<int> getMaxMinResult() {
    vector<int> results;

    do {
        int answer = nums[0];

        for (int i = 1; i < n; i++) {
            answer = calcByOper(answer, nums[i], operVec[i - 1]);
        }
        results.push_back(answer);
    } while (next_permutation(operVec.begin(), operVec.end()));

    vector<int> answer;
    answer.push_back(*max_element(results.begin(), results.end()));
    answer.push_back(*min_element(results.begin(), results.end()));

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    makeVec();

    vector<int> answer = getMaxMinResult();
    for (auto& elem : answer) {
        cout << elem << endl;
    }
}