/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: dfs/bfs
 * @level: 3
 * @prob_name: 여행경로
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/43164
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<string> airport;
vector<string> result;
int map[10000][10000] = {0};
int tic_size = 0, air_size = 0;
bool dfs_esc = false;

void DFS(int index, int dep) {
    if (index == tic_size) {
        dfs_esc = true;
        return;
    }

    for (int i = 0; i < air_size; i++) {
        if (map[dep][i] > 0) {
            map[dep][i]--;
            result.push_back(airport[i]);
            DFS(index + 1, i);
            if (dfs_esc) return;
            result.pop_back();
            map[dep][i]++;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    tic_size = tickets.size();

    string dep = "", dest = "";
    for (auto elem : tickets) {
        bool dep_c = true, dest_c = true;
        dep = elem[0];
        dest = elem[1];
        for (auto airline : airport) {
            if (dep == airline) dep_c = false;
            if (dest == airline) dest_c = false;
        }
        if (dep_c) airport.push_back(dep);
        if (dest_c) airport.push_back(dest);
    }

    sort(airport.begin(), airport.end());
    air_size = airport.size();

    int icn_index = 0;
    for (int i = 0; i < air_size; i++)
        if ("ICN" == airport[i]) icn_index = i;

    for (int i = 0; i < tic_size; i++) {
        int dep_i = 0, dest_i = 0;
        for (int j = 0; j < air_size; j++) {
            if (tickets[i][0] == airport[j]) dep_i = j;
            if (tickets[i][1] == airport[j]) dest_i = j;
        }
        map[dep_i][dest_i]++;
    }

    result.push_back(airport[icn_index]);
    DFS(0, icn_index);

    answer = result;
    return answer;
}

int main() {
    vector<vector<string>> tickets = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}};
    vector<string> answer = solution(tickets);
    for (auto elem : answer) {
        cout << elem << " ";
    }
    cout << endl;
}