/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Math
 * @prob_name: 달팽이는 올라가고 싶다
 * @prob_number: 2869
 * @prob_url: https://www.acmicpc.net/problem/2869
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int a;
    int b;
    int v;
    cin >> a >> b >> v;

    int finV = v - a;
    int dayV = a - b;

    if (finV % dayV == 0) {
        cout << (finV / dayV + 1);
    } else {
        cout << (finV / dayV + 2);
    }
}