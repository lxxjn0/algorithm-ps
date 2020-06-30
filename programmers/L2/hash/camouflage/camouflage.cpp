/**
 * @author: junyoung lee - lxxjn0
 * @site: programmers
 * @classification: hash
 * @level: 2
 * @prob_name: 위장
 * @prob_url: https://programmers.co.kr/learn/courses/30/lessons/42578
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<string, int> clothes_map;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    for (auto elem : clothes) {
        clothes_map[elem[1]]++;  // 의상 종류별로 갯수 측정
    }

    vector<int> clothes_count;  // 의상 종류별 개수만 저장하는 vector

    for (auto elem : clothes_map) {
        int tmp = elem.second;
        clothes_count.push_back(tmp);
        answer *= tmp;  // 의상 종류를 1개만 선택하는 경우를 미리 계산
    }

    int clothes_count_size = clothes_count.size();

    if (clothes_count_size == 1) {  // 의상의 종류가 1가지이면 바로 답을 반환
        return answer;
    }

    // 의상 종류별 개수중 가장 큰 값이 1이라면 2^의상 종류 - 1이 답이 됨
    if (*max_element(clothes_count.begin(), clothes_count.end()) == 1) {
        return pow(2, clothes_count_size) - 1;
    }

    int half_count_size = clothes_count_size / 2;  // 조합 계산이 nCa == nCn-a인 원리를 이용해서 절반만 계산
    bool is_even = clothes_count_size % 2 == 0;    // 짝수인 경우에 예외를 처리하기 위해

    for (int i = 0; i < half_count_size; ++i) {
        vector<int> v;

        // 조합(combination)을 사용하기 위해 permutation 배열 생성
        for (int j = 0; j < clothes_count_size; ++j) {
            if (j <= i) {
                v.push_back(0);
            } else {
                v.push_back(1);
            }
        }

        do {
            int comb_sum_1 = 1, comb_sum_2 = 1;  // nCa와 nCn-a를 각각 계산할 변수

            for (int j = 0; j < clothes_count_size; ++j) {
                if (v[j] == 0) {
                    comb_sum_1 *= clothes_count[j];
                } else {
                    comb_sum_2 *= clothes_count[j];
                }
            }

            // 짝수일 경우 중간에 2번 연산되는 경우를 제거하기 위한 연산
            if (is_even && i == half_count_size - 1) {
                answer += comb_sum_1;
            } else {
                answer += (comb_sum_1 + comb_sum_2);
            }
        } while (next_permutation(v.begin(), v.end()));
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<vector<string>>> clothes = {
        {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}},
        {{"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"}}};

    for (auto elem : clothes) {
        cout << solution(elem) << endl;
    }
}