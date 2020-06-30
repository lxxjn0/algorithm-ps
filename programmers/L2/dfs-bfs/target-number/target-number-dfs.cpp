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

int target_count = 0;

using namespace std;

void DFS(vector<int>& numbers, int depth, int sum, int target) {
    if (depth == numbers.size()) {
        if (sum == target) {
            target_count++;
        }
        return;
    }

    DFS(numbers, depth + 1, sum + numbers[depth], target);
    DFS(numbers, depth + 1, sum - numbers[depth], target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int sum = 0;

    DFS(numbers, 0, sum, target);

    answer = target_count;
    return answer;
}

int main() {
    vector<int> numbers = {1, 1, 1, 1, 1};
    int target = 3;
    cout << solution(numbers, target) << endl;
}