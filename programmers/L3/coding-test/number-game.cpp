/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: 서머코딩/윈터코딩(2018)
 * @level: 3
 * @prob_name: 숫자 게임
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/12987
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int a_size = A.size();
    int b_size = B.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int a_idx = 0;
    int b_idx = 0;
    while ((a_idx < a_size) && (b_idx < b_size)) {
        if (A[a_idx] < B[b_idx]) {
            answer++;
            a_idx++;
            b_idx++;
        }
        else {
            b_idx++;
        }
    }
    
    return answer;
}

int main() {
    vector<int> A = {5, 1, 3, 7};
    vector<int> B = {2, 2, 6, 8};
    cout << solution(A, B) << endl;
}