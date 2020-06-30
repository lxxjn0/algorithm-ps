/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: dfs/bfs
 * @level: 2
 * @prob_name: 타겟 넘버
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/43165
 */

#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

queue<pair<int, int>> q;

int BFS(vector<int>& numbers, int target) {
    q.push(make_pair(-1, 0));  // 앞이 인덱스(높이), 뒤가 sum
    int x, y;
    int count = 0;
    int size_num = numbers.size();

    while (!q.empty()) {
        tie(y, x) = q.front();
        q.pop();

        if ((y == size_num - 1) && (x == target)) count++;
        if (y < size_num - 1) {
            q.push(make_pair(y + 1, x + numbers[y + 1]));
            q.push(make_pair(y + 1, x - numbers[y + 1]));
        }
    }
    return count;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    answer = BFS(numbers, target);
    return answer;
}

int main() {
    vector<int> numbers = {1, 1, 1, 1, 1};
    int target = 3;
    cout << solution(numbers, target) << endl;
}