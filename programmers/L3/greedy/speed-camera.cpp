/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: greedy
 * @level: 3
 * @prob_name: 단속카메라
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42884
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef pair<int, int> path;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<path> paths;  // paths에 routes에서 겹치는, 카메라를 둘 수 있는 후보지의 경로를 저장
    int routes_size = routes.size();
    sort(routes.begin(), routes.end());  // 출발 시점이 작은 순으로 정렬하기 위해 sort 진행
    paths.push_back(make_pair(routes[0][0], routes[0][1]));

    int paths_size = paths.size();
    int path_start = 0, path_end = 0;
    int routes_start = 0, routes_end = 0;
    int new_start = 0, new_end = 0;
    bool exists = false;
    for (int i = 1; i < routes_size; i++) {
        exists = false;
        routes_start = routes[i][0];
        routes_end = routes[i][1];
        paths_size = paths.size();
        for (int j = 0; j < paths_size; j++) {
            path_start = paths[j].first;
            path_end = paths[j].second;
            if ((routes_start <= path_end) && (routes_end >= path_start)) {
                new_start = max(routes_start, path_start);
                new_end = min(routes_end, path_end);
                paths[j] = make_pair(new_start, new_end);
                exists = true;
                break;
            }
        }
        if (!exists) paths.push_back(make_pair(routes_start, routes_end));
    }
    answer = paths.size();
    // for(auto elem : paths){
    //     cout << elem.first << " " << elem.second << endl;
    // }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> routes = {{1, 6}, {2, 4}, {8, 11}, {9, 12}, {5, 10}, {3, 7}};
    cout << solution(routes) << endl;
}
