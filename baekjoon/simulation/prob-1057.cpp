/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Simulation
 * @prob_name: 토너먼트
 * @prob_number: 1057
 * @prob_url: https://www.acmicpc.net/problem/1057
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n = 0;
int a = 0;
int b = 0;

int getMeetRound() {
    int round = 1;
    while (true) {
        if (a % 2 == 1 && b - a == 1) {
            return round; 
        }
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        n = (n + 1) / 2;
        round++;
    }
}

int main() {
    cin >> n >> a >> b;

    if (a > b) {
        swap(a, b);
    }
    cout << getMeetRound();
}