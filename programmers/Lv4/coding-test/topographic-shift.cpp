/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: 서머코딩/윈터코딩(2019)
 * @level: 4
 * @prob_name: 지형 이동
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/62050
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <vector>

// 4가지 방향의 이동에 대한 설정
#define UP make_pair(0, -1)
#define DOWN make_pair(0, 1)
#define RIGHT make_pair(1, 0)
#define LEFT make_pair(-1, 0)

using namespace std;

typedef pair<int, int> ladder_pair;  // 사다리를 놓는 구간의 pair ex. (1, 2) -> 1번 색과 2번 색 구간 사이에 둘 사다리
typedef pair<int, int> coordinate;   // 좌표

queue<coordinate> q; // BFS에 사용할 queue
vector<vector<int>> color; // 색칠을 할 2차원 vector 배열
map<ladder_pair, int> ladder; // 사다리들의 값을 저장할 map

int land_size = 0;
int height_ = 0;

list<int> adjust[90000];  // 인접 리스트
int u_root[90000] = {0};  // root를 저장할 배열
int u_rank[90000] = {0};  // 높이를 저장할 배열

void make_set(int size) {  // Union root 배열과 rank 배열 초기화
    for (int i = 0; i < size; i++) {
        u_root[i] = i;
        u_rank[i] = 0;
    }
}

int find_rt(int x) {  // root를 찾는 함수
    if (u_root[x] == x)
        return x;
    else
        return u_root[x] = find_rt(u_root[x]);  // root를 찾아서 최종루트로 초기화 후 return
}

bool union_set(int x, int y) {
    x = find_rt(x);
    y = find_rt(y);

    if (x == y)
        return true;  // root가 같으면 이미 사이클 생성
    else {
        if (u_rank[x] < u_rank[y])
            u_root[x] = y;
        else if (u_rank[x] > u_rank[y])
            u_root[y] = x;
        else {
            u_root[y] = x;
            u_rank[x]++;  // 높이가 같다면 높이가 1 증가하므로 x에 높이 증가
        }
        return false;
    }
}

bool compare(pair<ladder_pair, int> a, pair<ladder_pair, int> b) {
    return a.second < b.second;
}

int kruskal(vector<pair<ladder_pair, int>>& ladder_vec) {
    int total_cost = 0;
    int ladder_size = ladder_vec.size();
    sort(ladder_vec.begin(), ladder_vec.end(), compare);

    for (int i = 0; i < ladder_size; i++) {
        if (!union_set(ladder_vec[i].first.first, ladder_vec[i].first.second)) {
            total_cost += ladder_vec[i].second;
        }
    }
    return total_cost;
}

coordinate operator+(coordinate a, coordinate b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

// 불가능한 경우는 -1을 return
int get_color(coordinate coord, coordinate dir) {
    coordinate tmp = coord + dir;
    if (tmp.first > land_size - 1 || tmp.first < 0)
        return -1;
    else if (tmp.second > land_size - 1 || tmp.second < 0)
        return -1;
    else {
        return color[tmp.first][tmp.second];
    }
}

void set_dir_color(vector<vector<int>>& land, coordinate coord, coordinate dir, int color_num) {
    coordinate tmp_c = coord + dir;
    int tmp_h;

    int dir_color = get_color(coord, dir);
    if (dir_color == 0) {
        tmp_h = abs(land[coord.first][coord.second] - land[tmp_c.first][tmp_c.second]);
        if (tmp_h <= height_) {
            color[tmp_c.first][tmp_c.second] = color_num;
            q.push(tmp_c);
        }
    } else if (dir_color > 0) {
        ladder_pair tmp_l;
        tmp_h = abs(land[coord.first][coord.second] - land[tmp_c.first][tmp_c.second]);

        if (dir_color > color_num)
            tmp_l = make_pair(color_num, dir_color);
        else
            tmp_l = make_pair(dir_color, color_num);

        if (ladder.end() == ladder.find(tmp_l)) {
            ladder.insert(make_pair(tmp_l, tmp_h));
        } else if (ladder[tmp_l] > tmp_h)
            ladder[tmp_l] = tmp_h;
    }
}

void BFS(vector<vector<int>>& land, int color_num, coordinate coord) {
    color[coord.first][coord.second] = color_num;
    q.push(coord);
    while (!q.empty()) {
        coordinate tmp = q.front();
        q.pop();
        set_dir_color(land, tmp, UP, color_num);
        set_dir_color(land, tmp, DOWN, color_num);
        set_dir_color(land, tmp, RIGHT, color_num);
        set_dir_color(land, tmp, LEFT, color_num);
    }
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    land_size = land.size();
    height_ = height;
    // land와 같은 크기의 color vector 생성
    color.assign(land_size, vector<int>(land_size, 0));

    int color_num = 1;
    for (int i = 0; i < land_size; i++) {
        for (int j = 0; j < land_size; j++) {
            if (color[i][j] == 0) {
                coordinate coord = make_pair(i, j);
                BFS(land, color_num, coord);
                color_num++;
            }
        }
    }

    vector<pair<ladder_pair, int>> ladder_vec;

    for(auto elem : ladder) {
        ladder_vec.push_back(make_pair(make_pair(elem.first.first - 1, elem.first.second - 1), elem.second)); // 인덱스 시작을 0으로 맞춰주기 위해
        adjust[elem.first.first].push_back(elem.first.second);
    }
    make_set(color_num);    // color_num의 개수 = 노드의 개수

    answer = kruskal(ladder_vec);
    return answer;
}

int main() {
    vector<vector<int>> land = {
        {10, 11, 10, 11},
        {2, 21, 20, 10},
        {1, 20, 21, 11},
        {2, 1, 2, 1}};
    int height = 1;
    cout << solution(land, height) << endl;
}