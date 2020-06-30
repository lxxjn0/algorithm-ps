/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Math
 * @prob_name: 직사각형에서 탈출
 * @prob_number: 1085
 * @prob_url: https://www.acmicpc.net/problem/1085
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int MinHorizontalEscape(int x, int w) {
    return min(x, w - x);
}

int MinVerticalEscape(int y, int h) {
    return min(y, h - y);
}

int EscapeRectangular(int x, int y, int w, int h) {
    return min(MinHorizontalEscape(x, w), MinVerticalEscape(y, h));
}

int main() {
    int x;
    int y;
    int w;
    int h;
    cin >> x >> y >> w >> h;

    cout << EscapeRectangular(x, y, w, h) << endl;
}