/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: DFS
 * @prob_name: 로또
 * @prob_number: 6603
 * @prob_url: https://www.acmicpc.net/problem/6603
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define LOTTO_NUMBER 6

using namespace std;

vector<int> lottoNums;
vector<int> comb;
int k = 0;

void makeLottoNums() {
    lottoNums.assign(k, 0);
    comb.assign(k, 0);

    for (int i = 0; i < k; i++) {
        cin >> lottoNums[i];

        if (i < LOTTO_NUMBER) {
            comb[i] = 0;
        } else {
            comb[i] = 1;
        }
    }

    sort(lottoNums.begin(), lottoNums.end());
}

void printLottoNum() {
    do {
        for (int i = 0; i < k; i++) {
            if (!comb[i]) {
                cout << lottoNums[i] << " ";
            }
        }
        cout << endl;
    } while (next_permutation(comb.begin(), comb.end()));
}

void init() {
    lottoNums.clear();
    comb.clear();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        cin >> k;

        if (!k) {
            break;
        }

        init();
        makeLottoNums();
        printLottoNum();
        cout << endl;
    }
}