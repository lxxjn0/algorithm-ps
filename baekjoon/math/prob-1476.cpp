/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Math
 * @prob_name: 날짜계산
 * @prob_number: 1476
 * @prob_url: https://www.acmicpc.net/problem/1476
 */

#include <iostream>
#include <string>
#include <vector>

#define E_UNIT 15
#define S_UNIT 28
#define M_UNIT 19

using namespace std;

int E = 0;
int S = 0;
int M = 0;

bool isCorrectYear(int& calc_e, int& calc_s, int& calc_m) {
    return (calc_e == E) && (calc_s == S) && (calc_m == M);
}

int getRealYear() {
    int year = 0;
    int calc_e;
    int calc_s;
    int calc_m;

    while(true) {
        calc_e = year % E_UNIT;
        calc_s = year % S_UNIT;
        calc_m = year % M_UNIT;
        year++;
        
        if (isCorrectYear(calc_e, calc_s, calc_m)) {
            break;
        }
    }
    return year;
}

int main() {
    cin >> E >> S >> M;
    E--;
    S--;
    M--;

    cout << getRealYear();
}