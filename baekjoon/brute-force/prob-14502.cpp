/**
 * @author: junyoung lee - lxxjn0
 * @site: baekjoon online judge
 * @classification: Brute force
 * @prob_name: 연구소
 * @prob_number: 14502
 * @prob_url: https://www.acmicpc.net/problem/14502
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define SPACE 0
#define WALL 1
#define VIRUS 2
#define N make_pair(-1, 0)
#define E make_pair(0, 1)
#define S make_pair(1, 0)
#define W make_pair(0, -1)

using namespace std;

typedef pair<int, int> coord;
vector<vector<int>> lab;
vector<coord> spaces;
vector<coord> viruses;
vector<coord> direction = {N, E, S, W};
vector<int> comb;
int n = 0;
int m = 0;

coord operator+(coord& c1, coord& c2) {
    return make_pair(c1.first + c2.first, c1.second + c2.second);
}

bool IsRange(coord& pos) {
    if (pos.first < 0 || pos.first >= n) {
        return false;
    }
    if (pos.second < 0 || pos.second >= m) {
        return false;
    }
    return true;
}

void SetIsNotWall(int pos, int row, int column) {
    if (pos == SPACE) {
        spaces.push_back(make_pair(row, column));
    } else if (pos == VIRUS) {
        viruses.push_back(make_pair(row, column));
    }
}

void MakeLabStatus() {
    lab.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int pos;
            cin >> pos;

            lab[i][j] = pos;
            SetIsNotWall(pos, i, j);
        }
    }
}

void MakeCombVector() {
    int spaces_size = spaces.size();

    for (int i = 0; i < spaces_size; i++) {
        comb.push_back(i < 3 ? 0 : 1);
    }
}

void SetSelectedSpaceStatus(int status, vector<coord>& make_wall_coord) {
    int make_wall_coord_size = make_wall_coord.size();

    for (int i = 0; i < make_wall_coord_size; i++) {
        coord pos = make_wall_coord[i];

        lab[pos.first][pos.second] = status;
    }
}

bool IsSpace(coord& pos) {
    return lab[pos.first][pos.second] == SPACE;
}

int VirusDFS(coord& pos) {
    int virus_count = 0;

    for (auto& dir : direction) {
        coord next_pos = dir + pos;

        if (IsRange(next_pos) && IsSpace(next_pos)) {
            lab[next_pos.first][next_pos.second] = VIRUS;
            virus_count += VirusDFS(next_pos);
            virus_count++;
        }
    }
    return virus_count;
}

int SpreadVirus() {
    int additional_virus = 0;
    int viruses_size = viruses.size();

    for (int i = 0; i < viruses_size; i++) {
        additional_virus += VirusDFS(viruses[i]);
    }
    return additional_virus;
}

int FindSafeArea() {
    vector<vector<int>> init_lab = lab;
    int spaces_size = spaces.size();
    int answer = 0;

    do {
        vector<coord> make_wall_coord;

        lab = init_lab;
        int cur_remain_space = spaces_size;

        for (int i = 0; i < spaces_size; i++) {
            if (comb[i] == 0) {
                make_wall_coord.push_back(spaces[i]);
                cur_remain_space--;
            }
        }
        SetSelectedSpaceStatus(WALL, make_wall_coord);
        cur_remain_space -= SpreadVirus();

        if (answer < cur_remain_space) {
            answer = cur_remain_space;
        }
    } while (next_permutation(comb.begin(), comb.end()));

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    MakeLabStatus();
    MakeCombVector();

    cout << FindSafeArea() << "\n";
}