/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: 서머코딩/윈터코딩(2018)
 * @level: 3
 * @prob_name: 방문 길이
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/49994
 */

#include <iostream>
#include <set>
#include <string>

using namespace std;

typedef pair<int, int> coordinate;

int solution(string dirs) {
    int answer = 0;
    int dirs_size = dirs.length();
    set<pair<coordinate, coordinate>> road;

    int prev_x = 0;
    int prev_y = 0;
    int next_x = 0;
    int next_y = 0;
    for (int i = 0; i < dirs_size; i++) {
        if (dirs[i] == 'U') {
            next_x = prev_x;
            next_y = prev_y + 1;
        } else if (dirs[i] == 'D') {
            next_x = prev_x;
            next_y = prev_y - 1;
        } else if (dirs[i] == 'R') {
            next_x = prev_x + 1;
            next_y = prev_y;
        } else {
            next_x = prev_x - 1;
            next_y = prev_y;
        }
        if (!(next_x > 5 || next_x < -5 || next_y > 5 || next_y < -5)) {
            if (prev_x < next_x) {
                road.insert(make_pair(make_pair(prev_x, prev_y), make_pair(next_x, next_y)));
            } else if (prev_x > next_x) {
                road.insert(make_pair(make_pair(next_x, next_y), make_pair(prev_x, prev_y)));
            } else {
                if (prev_y < next_y) {
                    road.insert(make_pair(make_pair(prev_x, prev_y), make_pair(next_x, next_y)));
                } else {
                    road.insert(make_pair(make_pair(next_x, next_y), make_pair(prev_x, prev_y)));
                }
            }
            prev_x = next_x;
            prev_y = next_y;
        }
    }
    return road.size();
}

int main() {
    string dir = "LULLLLLLU";
    cout << solution(dir) << endl;
}