/**
 * @author: junyoung lee - lxxjn0
 * @site: programmmers
 * @classification: heap
 * @level: 3
 * @prob_name: 디스크 컨트롤러
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42627
 */

#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
// pq의 앞은 작업 길이, 뒤는 작업 요청 시간
typedef pair<int, int> job_pair;
priority_queue<job_pair, vector<job_pair>, greater<job_pair>> pq;  // Min-heap

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    sort(jobs.begin(), jobs.end());
    int jobs_size = jobs.size(), idx = 0, end_t = 0;
    job_pair cur_j, next_j;

    if (jobs[idx][0] > 0) end_t = jobs[idx][0];
    pq.push(make_pair(jobs[idx][1], jobs[idx][0]));
    idx++;

    while (idx < jobs_size) {
        // 작업을 pop 할 때, answer에 추가.

        if (!pq.empty()) {
            cur_j = pq.top();
            pq.pop();              // 진행될 작업.
            end_t += cur_j.first;  // 현재 들어간 작업이 종료될 시각.
            answer += (end_t - cur_j.second);

            while (idx < jobs_size) {
                next_j = make_pair(jobs[idx][1], jobs[idx][0]);  // 다음 작업 요청 시간
                if (next_j.second <= end_t) {                    // 현재 스케줄링 가능한 작업은 모두 추가
                    pq.push(next_j);
                    idx++;
                } else
                    break;
            }
        } else {
            next_j = make_pair(jobs[idx][1], jobs[idx][0]);  // 다음 작업 요청 시간
            pq.push(next_j);
            idx++;
            end_t += (next_j.second - end_t);
        }
    }

    while (!pq.empty()) {
        cur_j = pq.top();
        pq.pop();              // 진행될 작업.
        end_t += cur_j.first;  // 현재 들어간 작업이 종료될 시각.
        answer += (end_t - cur_j.second);
    }

    answer /= jobs_size;
    return answer;
}

int main() {
    vector<vector<int>> jobs = {
        {0, 3},
        {1, 9},
        {2, 6}};

    cout << solution(jobs) << endl;
}