/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: 2017 카카오코드 예선
 * @level: 2
 * @prob_name: 카카오 프렌즈 컬러링북
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/1829
 */

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> coordinate;
vector<vector<int>> visited;
int m_;
int n_;

void check_color(int& count, int color, coordinate coord, vector<vector<int>> picture, queue<coordinate>& q) {
    if (coord.first > 0) {
        if (visited[coord.first - 1][coord.second] == 0 && picture[coord.first - 1][coord.second] == color) {
            visited[coord.first - 1][coord.second] = 1;
            q.push(make_pair(coord.first - 1, coord.second));
            count++;
        }
    }

    if (coord.first < m_ - 1) {
        if (visited[coord.first + 1][coord.second] == 0 && picture[coord.first + 1][coord.second] == color) {
            visited[coord.first + 1][coord.second] = 1;
            q.push(make_pair(coord.first + 1, coord.second));
            count++;
        }
    }

    if (coord.second > 0) {
        if (visited[coord.first][coord.second - 1] == 0 && picture[coord.first][coord.second - 1] == color) {
            visited[coord.first][coord.second - 1] = 1;
            q.push(make_pair(coord.first, coord.second - 1));
            count++;
        }
    }

    if (coord.second < n_ - 1) {
        if (visited[coord.first][coord.second + 1] == 0 && picture[coord.first][coord.second + 1] == color) {
            visited[coord.first][coord.second + 1] = 1;
            q.push(make_pair(coord.first, coord.second + 1));
            count++;
        }
    }
}

int BFS(int x, int y, vector<vector<int>> picture) {
    int count = 1;
    int color = picture[x][y];
    visited[x][y] = 1;

    queue<coordinate> q;
    q.push(make_pair(x, y));

    while (!q.empty()) {
        coordinate coord = q.front();
        q.pop();
        check_color(count, color, coord, picture, q);
    }
    return count;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    visited.assign(100, vector<int>(100, 0));
    m_ = m;
    n_ = n;

    vector<int> v;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((picture[i][j] != 0) && (visited[i][j] == 0)) {
                v.push_back(BFS(i, j, picture));
                answer[0]++;
            }
        }
    }

    answer[1] = *max_element(v.begin(), v.end());
    return answer;
}

int main() {
    int m = 4;
    int n = 4;
    vector<vector<int>> picture = {
        {1, 1, 1, 0},
        {1, 0, 0, 1},
        {0, 2, 1, 0},
        {0, 1, 2, 0}};

    vector<int> answer = solution(m, n, picture);
    for (auto& elem : answer) {
        cout << elem << " ";
    }
    cout << endl;
}