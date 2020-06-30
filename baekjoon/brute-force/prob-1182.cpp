/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Brute force
 * @prob_name: 부분수열의 합
 * @prob_number: 1182
 * @prob_url: https://www.acmicpc.net/problem/1182
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sequence;
int n = 0;
int s = 0;

void makeSequence() {
    sequence.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
}

vector<int> makeCombVec(int selectNum) {
    vector<int> comb;

    for (int i = 0; i < n; i++) {
        comb.push_back(i < selectNum ? 0 : 1);
    }

    return comb;
}

int findPartialSequence() {
    int answer = 0;
    
    for (int i = 1; i <= n; i++) {
        vector<int> comb = makeCombVec(i);

        do {
            int sum = 0;

            for (int i = 0; i < n; i++) {
                if (comb[i] == 0) {
                    sum += sequence[i];
                }
            }

            if (sum == s) {
                answer++;
            }
        } while (next_permutation(comb.begin(), comb.end()));
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;

    makeSequence();
    cout << findPartialSequence();
}